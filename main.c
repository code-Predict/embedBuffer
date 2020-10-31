/*
 * キュー 
*/
#include <stdio.h>
#include <pthread.h>
#include "BufferThreads.h"
#include "Buffer.h"

int main(int argc, char const *argv[]) {
    // キュー初期化
    Buffer buffer, *Q;
    Q = &buffer;
    initBuffer(Q);

    // enBufferスレッド・deBufferスレッドを立てる
    int endReq = 0;
    BufferConf conf;
    conf.Q = Q;
    conf.timeout = 10;
    conf.endReq = &endReq;

    pthread_t eqThread, dqThread;
    pthread_create(&dqThread, NULL, deBufferThread, &conf);
    pthread_create(&eqThread, NULL, enBufferThread, &conf);

    //
    printf("Type any key to endReq.\n");
    while(getc(stdin) != '\n');
    *(conf.endReq) = 1;
    printf("## endReq ##\n");
    
    deinitBuffer(Q);
    return 0;
}
