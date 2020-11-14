bufferPath = -I ./
includePath = $(bufferPath)

# build examples
PHONY: examples
examples: examples/demo.c examples/bufhack.c examples/advance.c Buffer.dll
	gcc $(includePath) Buffer.dll examples/demo.c -o demo.out
	gcc $(includePath) Buffer.dll examples/bufhack.c -o bufhack.out
	gcc $(includePath) Buffer.dll examples/advance.c -o advance.out

# for C
a.out: examples/demo.c Buffer.dll
	gcc $(includePath) Buffer.dll examples/demo.c

#for C++
cpp: main.cpp Buffer.dll 
	gcc $(includePath) Buffer.dll main.cpp

# Buffer library build
Buffer.dll: Buffer.h Dump.c Initializer.c Operate.c
	gcc $(bufferPath) -c Dump.c 
	gcc $(bufferPath) -c Initializer.c
	gcc $(bufferPath) -c Operate.c
	gcc $(bufferPath) -c Lock.c
	gcc Dump.o Initializer.o Operate.o Lock.o -fPIC -shared -o Buffer.dll