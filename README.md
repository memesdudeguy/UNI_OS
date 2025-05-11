# UNI_OS ReactOS Custom ISO

This project builds a **custom ReactOS ISO** with UNI_OS integration, including:

- 🪟 Kernel spoofing shim (reports Windows 10/11 for compatibility)
- 🤖 Waydroid container launcher stub
- ⚙️ SATA/AHCI support (UniATA)
- 🧰 XP-compatible drivers and developer tools

---

## 🏗️ Build Instructions

### Prerequisites

- OS: Linux (or WSL2)
- Tools: `git`, `ninja`, `patch`, `cmake`, `make`
- RosBE or MinGW toolchain for ReactOS (https://reactos.org/wiki/Build_Environment)

### Steps

```bash
git clone https://github.com/yourusername/uni_os_reactos.git
cd uni_os_reactos
chmod +x build_uni_os_iso.sh
./build_uni_os_iso.sh
```

The output ISO will be:  
`UNI_OS_ReactOS.iso`

---

## 🔧 Modules Included

| Component             | Path                                |
|-----------------------|--------------------------------------|
| Kernel Spoof Shim     | `uni_os_addons/kernel_shims/ntquery_patch.c` |
| Waydroid Launcher Stub| `uni_os_addons/waydroid_stub/waydroid_launcher.cpp` |
| Build Hook Patch      | `uni_os_addons/patches/reactos_cmake_patch.diff` |

---

## 📦 Output Image

The ISO is bootable via **Legacy BIOS (MBR)** and includes:
- Basic VESA graphics fallback
- PS/2 + USB keyboard/mouse support
- Debug and Safe Mode boot options

---

## 🧪 Tested On

- Dell OptiPlex 780 (BIOS)
- Lenovo ThinkPad T61
- VirtualBox 7.x (Legacy mode)

---

## 🔍 Credits

- [ReactOS](https://reactos.org)
- [Waydroid](https://waydroid.org)
- [OpenAI's ChatGPT](https://chat.openai.com)

---

> ⚠️ Warning: This ISO is experimental and not officially supported by the ReactOS team.
