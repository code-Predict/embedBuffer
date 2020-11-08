bufferPath = -I ./
includePath = $(bufferPath)

# for C
a.out: main.c Buffer.dll
	gcc $(includePath) Buffer.dll main.c

#for C++
cpp: main.cpp Buffer.dll 
	gcc $(includePath) Buffer.dll main.cpp

Buffer.dll: Buffer.h Dump.c Initializer.c Operate.c
	gcc $(bufferPath) -c Dump.c 
	gcc $(bufferPath) -c Initializer.c
	gcc $(bufferPath) -c Operate.c
	gcc Dump.o Initializer.o Operate.o -fPIC -shared -o Buffer.dll