mkdir -p obj

src="."
obj="$src/obj"

FLAGS_ANSI="\
    -S \
    -Os \
    -std=c89 \
    -ansi \
    -pedantic \
    -Wall"
FLAGS_x86="\
    -S \
    -Os \
    -masm=intel \
    -pedantic \
    -Wall"

C_FLAGS=$FLAGS_x86

echo Compiling sources...
cc -o $obj/calculator.asm       $src/calculator.c $C_FLAGS

echo Assembling compiled sources...
as -o $obj/calculator.o         $obj/calculator.asm

echo Linking assembled object files...
gcc -o $src/calc $obj/calculator.o -s
