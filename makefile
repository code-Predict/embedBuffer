bufferPath = -I Buffer/
includePath = $(bufferPath)

# for C
a.out: main.c Buffer.dll
	gcc $(includePath) Buffer.dll main.c

#for C++
cpp: main.cpp Buffer.dll 
	gcc $(includePath) Buffer.dll main.cpp

Buffer.dll: Buffer/Buffer.h Buffer/Dump.c Buffer/Initializer.c Buffer/Operate.c
	gcc $(bufferPath) -c Buffer/Dump.c 
	gcc $(bufferPath) -c Buffer/Initializer.c
	gcc $(bufferPath) -c Buffer/Operate.c
	gcc Dump.o Initializer.o Operate.o -fPIC -shared -o Buffer.dll