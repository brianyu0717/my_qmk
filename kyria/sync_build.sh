#! /bin/bash

rsync -vhr yboen /home/brian/qmk_firmware/keyboards/splitkb/kyria/keymaps/ && qmk compile -kb splitkb/kyria/rev1 -km yboen