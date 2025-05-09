# UNI-OS

UNI-OS is a hybrid operating system designed to provide a seamless experience for running Linux applications, Windows `.exe` files (with kernel-level anti-cheat support), and Android `.apk` files. It features a Linux-like environment with the KDE desktop as the default user interface.

## Features
- **Kernel-Level Anti-Cheat Support**: Leveraging the double-hash `##gclib` library for secure execution of games and applications with anti-cheat mechanisms.
- **Compatibility Layers**: Run Linux, `.exe`, and `.apk` files natively.
- **Unified File Format**: `.exe` and `.apk` files can be converted into `.run` files for execution.
- **Live ISO**: Boot UNI-OS from a live ISO for easy installation.
- **KDE Desktop**: Latest KDE Plasma environment for a modern and customizable user interface.
- **Linux Drivers**: Full support for Linux hardware drivers.

## Getting Started
1. Download the live ISO from the official website.
2. Create a bootable USB drive using tools like Rufus or Etcher.
3. Boot from the USB drive and follow the on-screen instructions to install UNI-OS.

## Development
- **Exclusively Written in C++**: All core components, including the kernel, compatibility layers, and utilities, are implemented in C++.
- **Open Source**: UNI-OS is free and open for everyone to use and contribute.

## Roadmap
- Implement advanced process scheduling and memory management.
- Develop robust `.exe` and `.apk` compatibility layers.
- Expand `.run` file execution capabilities.
-