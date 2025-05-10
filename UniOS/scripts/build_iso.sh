#!/bin/bash

# Simple script to build an ISO for UNI-OS

ISO_DIR=iso_build
mkdir -p $ISO_DIR/boot/grub
cp ./bootloader/grub.cfg $ISO_DIR/boot/grub/

# You'd need to copy your kernel and initrd images here
cp ./build/uni_kernel $ISO_DIR/boot/
cp ./build/initrd.img $ISO_DIR/boot/

# Build ISO using mkisofs or xorriso
xorriso -as mkisofs -o uni-os.iso -R -J $ISO_DIR
