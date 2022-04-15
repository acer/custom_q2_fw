#!/bin/sh

cp -rf ../qmk_firmware/keyboards/keychron/q2/ .
cp -f ../qmk_firmware/keychron_q2_rev_0111_acer.bin ./builds
git add .