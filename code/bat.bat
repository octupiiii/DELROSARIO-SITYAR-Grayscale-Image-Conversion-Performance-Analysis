nasm -f win64 asmfunc.asm
gcc -c cfile.c -o cfile.obj -m64
gcc cfile.obj asmfunc.obj -o cfile.exe -m64
cfile.exe
