; bootloader.s - Basic bootloader (minimal example)

global _start

section .text
_start:
    ; Initialize the screen (for text mode)
    mov ah, 0x0E
    mov al, 'L'
    int 0x10
    mov al, 'O'
    int 0x10
    mov al, 'A'
    int 0x10
    mov al, 'D'
    int 0x10

    ; Load the kernel from disk into memory (simplified)
    ; Assuming the kernel is at sector 2 and we load it into memory at 0x10000
    mov ah, 0x02   ; BIOS read disk
    mov al, 1       ; Number of sectors
    mov ch, 0       ; Cylinder (0)
    mov cl, 2       ; Sector (2)
    mov dh, 0       ; Head (0)
    mov dl, 0x80    ; Drive (0x80 for the first hard disk)
    mov es, 0x1000  ; Segment for kernel
    mov bx, 0x0000  ; Offset for kernel load
    int 0x13        ; BIOS interrupt to read the sector

    ; Jump to the loaded kernel code (at 0x10000)
    jmp 0x1000:0x0000

