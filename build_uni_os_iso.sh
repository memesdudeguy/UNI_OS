#!/bin/bash
# build_uni_os_iso.sh - UNI_OS Custom ReactOS ISO Builder Script

set -e

# === CONFIGURATION ===
REACTOS_REPO=https://github.com/reactos/reactos.git
REACTOS_BRANCH=master
UNI_OS_DIR=$PWD/uni_os_addons
BUILD_DIR=$PWD/reactos_build
OUTPUT_ISO=$PWD/UNI_OS_ReactOS.iso

# === SETUP ENVIRONMENT ===
echo "[+] Setting up build environment..."
mkdir -p $BUILD_DIR
cd $BUILD_DIR

echo "[+] Cloning ReactOS..."
git clone --depth=1 --branch $REACTOS_BRANCH $REACTOS_REPO src

# === APPLY UNI_OS PATCHES ===
echo "[+] Copying UNI_OS additions..."
cp -r $UNI_OS_DIR/* src/

# Example: kernel spoof shim stub
cp $UNI_OS_DIR/kernel_shims/ntquery_patch.c src/win32ss/ntquery_patch.c

# Waydroid Hook Stub
cp $UNI_OS_DIR/waydroid_stub/waydroid_launcher.cpp src/subsystems/waydroid_launcher.cpp

# Add build config entries (patch or override existing files)
patch -p1 < $UNI_OS_DIR/patches/reactos_cmake_patch.diff

# === BUILDING ISO ===
echo "[+] Building ISO..."
cd src
./configure.sh configure
ninja bootcd

cp output-MinGW-i386/bootcd.iso $OUTPUT_ISO

echo "[+] Build complete: $OUTPUT_ISO"
