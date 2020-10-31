/*
 * 処理
*/
#include "Buffer.h"

int enBuffer(Buffer* buffer, Item item){
    int *tail = &(buffer->tail);
    int *head = &(buffer->head);

    // tailの次=head -> 満杯
    if(((*tail) + 1) % (BUFFER_SIZE + 1) == *head){
        return BUFFER_FULL;
    }

    // 末尾に追加し、ポインタを進める 配列の終端にきたら先頭に戻る
    buffer->data[*tail] = item;
    (*tail)++;
    if(*tail > BUFFER_SIZE){
        *tail = 0;
    }
    buffer->length++;
    return BUFFER_OK;
}

int deBuffer(Buffer* buffer, Item* item){
    int *tail = &(buffer->tail);
    int *head = &(buffer->head);

    // head==tail -> キューは空
    if(*head == *tail){
        return BUFFER_EMPTY;
    }

    // 先頭から取り出し、ポインタを進める 配列の終端にきたら先頭に戻る
    *item = buffer->data[*head];
    (*head)++;
    if(*head > BUFFER_SIZE){
        *head = 0;
    }
    buffer->length--;
    return BUFFER_OK;
}