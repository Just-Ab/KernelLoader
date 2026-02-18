# C-Compilation
- Download i686 elf gcc: https://github.com/lordmilko/i686-elf-tools/releases
- Create a directory "Tools" and extract "i686 elf gcc", should look like follows:
```
      Directory: %Path%/KernelLoader\Tools


Mode                    Length Name
----                    ------ ----
d-----                         bin
d-----                         i686-elf
d-----                         include
d-----                         lib
d-----                         libexec
d-----                         share
```

# Assembling
- Msys2 with NASM.

# Making
- Open Msys2 in directory and run "Make All".

# Running
## Real Machine
- Use rufus to burn the compiled or pre-compiled file found in "/build/" to a usb flash drive and boot using legacy mode.

## Virtual Machine
- Use Bochs or Qemu.
