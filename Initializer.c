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
    return 0;
}

int deinitBuffer(Buffer* buffer){
    
    return 0;
}

void initItem(Item* item){
    item->id = 0;
    memset(item->data, '\0', 8);
}