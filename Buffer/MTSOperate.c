/*
 * 処理(Multi-Thread-Safe)
*/
#include "Buffer.h"

int enBufferMT(Buffer* buffer, Item item){
    int rst;
    pthread_mutex_lock(&(buffer->mutex));
    rst = enBuffer(buffer, item);
    pthread_mutex_unlock(&(buffer->mutex));
    pthread_cond_broadcast(&(buffer->isNotEmpty));
    return rst;
}

int deBufferMT(Buffer* buffer, Item *item){
    int rst;
    pthread_mutex_lock(&(buffer->mutex));
    rst = deBuffer(buffer, item);
    pthread_mutex_unlock(&(buffer->mutex));
    pthread_cond_broadcast(&(buffer->isNotFull));
    return rst;
}

// deBuffer, enBufferを待機する
int waitFordeBuffer(Buffer* buffer, int timeout){
    // timespec再計算
    struct timespec timeoutTS;
    calcTimeSpec(&timeoutTS,10);
    int stat = waitSignal(&(buffer->mutex), &(buffer->isNotEmpty), &timeoutTS);
    return stat;
}

int waitForenBuffer(Buffer* buffer, int timeout){
    // timespec再計算
    struct timespec timeoutTS;
    calcTimeSpec(&timeoutTS,10);
    int stat = waitSignal(&(buffer->mutex), &(buffer->isNotFull), &timeoutTS);
    return stat;
}

void calcTimeSpec(struct timespec* ts, int timeout){
    ts->tv_nsec = 0;
    ts->tv_sec = time(NULL) + timeout;
}

int waitSignal(pthread_mutex_t* mutex, pthread_cond_t* cond, struct timespec* ts){
    int stat = 0;
    pthread_mutex_lock(mutex);
    stat = pthread_cond_timedwait(cond, mutex, ts);
    pthread_mutex_unlock(mutex);
    return stat;
}
