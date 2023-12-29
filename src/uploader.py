import serial
import subprocess
import os
import re
import sys


SDCC_PATH = "/usr/bin/sdcc"
PACKIHX = "/usr/bin/packihx"
PATH_TO_HEADER_FILE = "/home/pavel/hobby/SDK1.1/simple_test_sdcc/try2/"


def add_address_to_end_hex_file(path_to_hex_file):
    with open(path_to_hex_file, "a") as file:
        file.write(":022100060000D7\n")
        

def remove_extra_file(path_to_folder: str) -> None:
    # ^(?!.*(\.c$|\.hex$)).*$
    # basename = os.path.abspath(path_to_folder)
    extra_file = r".*\.(asm|ihx|lk|lst|map|rel|rst|sym|mem)$"
    directory = os.fsencode(path_to_folder)
    for file in os.listdir(directory):
        filename = os.fsdecode(file)
        if re.search(extra_file, filename) is not None:
            full_path_to_delete = os.path.join(path_to_folder, filename)
            os.remove(full_path_to_delete)


def create_hex_file(path_to_c_file: str)-> None:
    basename, c_filename = os.path.split(path_to_c_file)
    basename = os.path.join(basename, '')
    ihx_filename = re.sub(r"\.c$", ".ihx", c_filename)
    hex_filename = re.sub(r"\.c$", ".hex", c_filename)
    path_to_ihx_file = os.path.join(basename, ihx_filename)
    path_to_hex_file =  os.path.join(basename, hex_filename)

    cmd = [
        SDCC_PATH,
        "--model-large",
        "--stack-auto",
        "-mmcs51",
        "--opt-code-size",
        "--code-loc",
        "0x2100",
        "-I", 
        PATH_TO_HEADER_FILE,
        path_to_c_file,
        "-o",
        basename]

    process1 = subprocess.run(cmd)
    if process1.returncode != 0: raise Exception("[ERROR] Ошибка на этапе компиляции:")
    cmd = [ PACKIHX, path_to_ihx_file ]

    with open(path_to_hex_file, "w") as outfile:
        process2 = subprocess.run(cmd, stdout=outfile)
    if process2.returncode != 0: raise Exception("[ERROR] Ошибка на этапе добавления адреса в конец hex файла:")
    return path_to_hex_file


def waiting(port):
    while True:
        rcv = port.read(1)
        if rcv != b'' : print("[PORT]:", rcv)
        if rcv == b'.':
            break
    

def check(port):
    while True:
        rcv = port.read(1)
        if rcv != b'' : print("[PORT]:", rcv)
        if rcv == b'+':
            return True
        elif rcv == b'-':
            return False
        

def send_line(port, line):
    encode_line = line.encode()
    while True:
        port.write(encode_line)
        if check(port): break


def uploader(port, path_to_hex_file, infinitely):
    with open(path_to_hex_file) as file:
        lines = file.readlines()
        for index, line in enumerate(lines, start=1):
            print("[ME]:", line.encode())
            send_line(port, line)
            if index == len(lines) and not infinitely: break
            waiting(port)
        port.close()


def main():
    try:
        path_to_c_file = sys.argv[1] if len(sys.argv) > 1 else "./main.c"
        infinitely = sys.argv[2] if len(sys.argv) > 2 else False
        infinitely = True if infinitely in ['-i', '-I'] else False
        abs_path_to_c_file = os.path.abspath(path_to_c_file)
        path_to_hex_file = create_hex_file(abs_path_to_c_file)
        basename, _ = os.path.split(path_to_hex_file)
        add_address_to_end_hex_file(path_to_hex_file)
        remove_extra_file(basename)
    except Exception as error:
        print("[ERROR] Ошибка на этапе подготовки файла прошивки:")
        print(error)
        return

    try:
        port = serial.Serial("/dev/ttyUSB0", baudrate=9600, timeout=0.3)
        print("[ME]: Start program!")
        print("[ME]: Push reset on SDK1.1")
        waiting(port)
        uploader(port, path_to_hex_file, infinitely)
    except Exception as error:
        print("[ERROR] Ошибка на этапе отправки файла прошивки")
        print("Сообщение об ошибке:\n", error)
        return


if __name__ == "__main__":
    main()
