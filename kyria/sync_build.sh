#! /bin/bash

rsync -vhr yboen /home/brian/qmk_firmware/keyboards/splitkb/kyria/keymaps/
echo "flash? [y,n]: "
read flash
if [ "$flash" = "y" ] 
then
COMMAND=flash
else
COMMAND=compile
fi
qmk $COMMAND -kb splitkb/kyria/rev1 -km yboen