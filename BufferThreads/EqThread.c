/*
 * 
*/
#include "BufferThreads.h"

void *enBufferThread(void *_conf){
    // コンフィグからキューとタイムアウト時間を取り出す
    BufferConf conf = *(BufferConf *)_conf;
    Buffer *buffer = conf.Q;
    int *endReq = conf.endReq;
    int cnt = 0;

    //n秒だけ怒涛のenBuffer
    time_t startTime;
    time(&startTime);
    int limit = 5;

    while (!*(endReq)) {
        char strBuffer[8] = "enBuffer";
        Item item;
        item.id = cnt;
        memcpy(item.data, strBuffer, 8);
        
        int enBufferStat = enBufferMT(buffer, item);
        if(enBufferStat == BUFFER_FULL){
            perror("### BUFFER FULL ###");
        }

        // idカウンタを進める
        cnt++;
        if(cnt > 0xFF){
            cnt = 0;
        }

        // 適当に時間待ち
        usleep(100);

        // 指定時間経過?
        if((time(NULL) - startTime) > limit){
            *endReq = 1;
            continue;
        }
    }

    printf("enBuffer Process finished.\n");
    pthread_cond_broadcast(&(buffer->isEnbufferFinished));
    pthread_exit(NULL);
}