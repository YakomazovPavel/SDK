import serial
port = serial.Serial("/dev/ttyUSB0", baudrate=9600, timeout=0.3)


while True:
    rcv = port.read(16)
    print(rcv)