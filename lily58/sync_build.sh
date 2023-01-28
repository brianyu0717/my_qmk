#! /bin/bash

rsync -vhr yboen /home/brian/qmk_firmware/keyboards/lily58/keymaps/ && qmk compile -kb lily58 -km yboen