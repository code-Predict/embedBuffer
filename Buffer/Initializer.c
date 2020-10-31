/*
 * 初期化
*/
#include "Buffer.h"

int initBuffer(Buffer* buffer){
    // Data
    for(int i = 0; i < BUFFER_SIZE; i++){
        initItem(&(buffer->data[i]));
    }
    buffer->head = 0;
    buffer->tail = 0;
    buffer->length = 0;

    // Thread
    int rst = 0;
    rst = pthread_mutex_init(&buffer->mutex, NULL);
    assert(rst == 0);
    rst = pthread_cond_init(&buffer->isNotEmpty, NULL);
    assert(rst == 0);
    rst = pthread_cond_init(&buffer->isNotFull, NULL);
    assert(rst == 0);
    rst = pthread_cond_init(&buffer->isDebufferFinished, NULL);
    assert(rst == 0);
    rst = pthread_cond_init(&buffer->isEnbufferFinished, NULL);
    assert(rst == 0);
    return rst;
}

int deinitBuffer(Buffer* buffer){
    int rst = 0;
    rst = pthread_cond_destroy(&buffer->isNotEmpty);
    assert(rst == 0);
    rst = pthread_cond_destroy(&buffer->isNotFull);
    assert(rst == 0);
    rst = pthread_cond_destroy(&buffer->isDebufferFinished);
    assert(rst == 0);
    rst = pthread_cond_destroy(&buffer->isEnbufferFinished);
    assert(rst == 0);
    rst = pthread_mutex_destroy(&buffer->mutex);
    assert(rst == 0);
    
    return rst;
}

void initItem(Item* item){
    item->id = 0;
    memset(item->data, '\0', 8);
}