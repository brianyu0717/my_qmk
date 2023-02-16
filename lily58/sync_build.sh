#! /bin/bash

rsync -vhr yboen /home/brian/qmk_firmware/keyboards/lily58/keymaps/
echo "flash? [y,n]: "
read flash
if [ "$flash" = "y" ] 
then
COMMAND=flash
else
COMMAND=compile
fi
qmk $COMMAND -kb lily58 -km yboen