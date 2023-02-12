#! /bin/bash

rsync -vhr yboen /home/brian/qmk_firmware/keyboards/lily58/keymaps/ && qmk compile -kb lily58 -km yboen
echo "flash? [y, n]: "
read flash
if [ "$flash" = "y" ] 
then
qmk flash -kb lily58 -km yboen
else
echo 'no flash'
fi