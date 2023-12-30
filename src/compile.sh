#!/bin/bash
sdcc --stack-auto --model-large -mmcs51 --opt-code-size --code-loc 0x2100 "./labs/7 Noise/noize.c" \
-o "/home/pavel/hobby/SDK/.temp/"  \
&& packihx "/home/pavel/hobby/SDK/.temp/noize.ihx" > "/home/pavel/hobby/SDK/hexs/7noize.hex" \
&& echo ":022100060000D7" >> "/home/pavel/hobby/SDK/hexs/7noize.hex"

# --xstack --xstack-loc 0x3000 
