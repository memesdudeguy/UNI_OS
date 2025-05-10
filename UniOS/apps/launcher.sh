#!/bin/bash

# wine_launcher.sh - A simple script to launch EXE files using Wine

if [ $# -lt 1 ]; then
    echo "Usage: wine_launcher <exe-file>"
    exit 1
fi

# Assuming Wine is installed
wine "$1"
