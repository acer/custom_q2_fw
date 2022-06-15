#!/bin/bash
if [[ $# -eq 0 ]]; then
echo 'need a unique name for bin file'
exit 0
fi 

\cp -r ../qmk_firmware/keyboards/keychron/q2 ./q2/
\cp -vr ../qmk_firmware/keychron_q2_rev_0111_acer.bin ./builds/keychron_q2_rev_0111_acer_$1.bin
