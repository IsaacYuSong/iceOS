clear
cd /mnt/c/Users/Isaac/OneDrive/Documents/Git/IceOs
export PATH=$PATH:/usr/local/i386elfgcc/bin
nasm "bootsector/boot.asm" -f bin -o "boot.bin"
nasm "bootsector/kernalEntry.asm" -f elf -o "kernel_entry.o"
nasm "bootsector/zeroes.asm" -f bin -o "zeroes.bin"


i386-elf-gcc -ffreestanding -m32 -g -c "kernel/kernel.c" -o "kernel.o"


i386-elf-ld -o "full_kernel.bin" -Ttext 0x1000 "kernel_entry.o" "kernel.o" --oformat binary

cat "boot.bin" "full_kernel.bin" "zeroes.bin" > "OS.bin"


qemu-system-i386 -drive format=raw,file="OS.bin",index=0,if=floppy -m 256M

