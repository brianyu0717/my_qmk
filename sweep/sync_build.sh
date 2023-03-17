#! /bin/bash

rsync -vhr yboen /home/brian/qmk_firmware/keyboards/ferris/keymaps/
echo "flash? [y,n]: "
read flash
if [ "$flash" = "y" ] 
then
COMMAND=flash
else
COMMAND=compile
fi

echo "left or right? [l,r]: "
read isleft
if [ "$isleft" = "l" ] 
then
HANDEDNESS=left
else
HANDEDNESS=right
fi
qmk $COMMAND -kb ferris/sweep -km yboen -bl avrdude-split-$HANDEDNESS