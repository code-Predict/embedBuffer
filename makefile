bufferPath = -I Buffer/ -I DqThread -I BufferThreads
includePath = $(bufferPath)

# for C
a.out: main.c Buffer.dll BufferThreads.dll
	gcc $(includePath) Buffer.dll BufferThreads.dll main.c -pthread

#for C++
cpp: main.cpp Buffer.dll 
	gcc $(includePath) Buffer.dll main.cpp

BufferThreads.dll: BufferThreads/BufferThreads.h BufferThreads/DqThread.c BufferThreads/EqThread.c
	gcc $(includePath) -c BufferThreads/DqThread.c -pthread
	gcc $(includePath) -c BufferThreads/EqThread.c -pthread
	gcc $(includePath) Buffer.dll DqThread.o EqThread.o -fPIC -shared -o BufferThreads.dll -pthread

Buffer.dll: Buffer/Buffer.h Buffer/Dump.c Buffer/Initializer.c Buffer/Operate.c Buffer/MTSOperate.c
	gcc $(bufferPath) -c Buffer/Dump.c 
	gcc $(bufferPath) -c Buffer/Initializer.c
	gcc $(bufferPath) -c Buffer/Operate.c -pthread
	gcc $(bufferPath) -c Buffer/MTSOperate.c -pthread
	gcc Dump.o Initializer.o Operate.o MTSOperate.o -fPIC -shared -o Buffer.dll -pthread