# My qmk customisations

Keymaps for my keyboards.

## Motivation

It's much easier to keep the keymaps etc in a separate repo and use `rsync` to drop them into the qmk repo and 
build qmk than to keep a fork of qmk and have it fall behind mainline qmk and doing painful rebases.

## How to use

General workflow is to modify files in here and `rsync` them to the checked-out `qmk_firmware` project. Then that can be build using qmk cli commands.

### Lily58

Run `sync_build.sh` in `/lily58`. Then flash the keyboard.

Everything in `yboen` directory will be `rsync`'d to qmk_firmware's lily58/keymaps directory by the `sync_build.sh` script. Additionally it calls qmk to build 
that keymap so it'll be ready for flashing.

### Kyria

No rsync is available and there's some left overs from merge conflict resolution that needs fixing. Fix those first, then create the rsync script similar to the lily58 one.