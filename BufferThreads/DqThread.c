/*
 * 
*/
#include "BufferThreads.h"

void *deBufferThread(void *_conf){
    // コンフィグからキューとタイムアウト時間を取り出す
    BufferConf conf = *(BufferConf *)_conf;
    Buffer *buffer = conf.Q;
    int *endReq = conf.endReq;

    // enBufferされたら表示する タイムアウト時スレッド終了
    int deBufferStat = BUFFER_OK, waitStat = 0;
    char strBuffer[35];
    while(!(*endReq)){
        Item item;
        deBufferStat = deBufferMT(buffer, &item);

        if(deBufferStat == BUFFER_OK){
            memset(strBuffer, 0, 35);
            dumpItem(&item, strBuffer);
        }else{
            waitStat = waitFordeBuffer(buffer, conf.timeout);
            if(waitStat == ETIMEDOUT){
                *endReq = 1;
                continue;
            }
        }
        usleep(1000);
    }

    printf("DeBufferThread: Timeout or detect signal.\n");
    pthread_cond_broadcast(&(buffer->isDebufferFinished));
    pthread_exit(NULL);
}