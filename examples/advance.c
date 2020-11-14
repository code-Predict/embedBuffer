/*
 * 任意位置のデータを取り出す
*/
#include <stdio.h>
#include "Buffer.h"

//
Buffer buffer, *B;

void dumpWithAdv();
void dumpWithPop();

int main(int argc, char *argv[]) {
    // buffer初期化
    unsigned int bufferLength = 20;
    B = &buffer;
    initBuffer(B, bufferLength);

    // バッファの半分までpush
    printf("push %d item.\n", bufferLength / 2);
    Item item;
    for (unsigned int i = 0; i < bufferLength / 2; i++) {
        initItem(&item);
        item.id = i;
        push(B, item);
    }

    // 読み出す
    dumpWithAdv();
    
    // バッファの1/4までpop
    printf("pop %d item.\n", bufferLength / 4);
    for (unsigned int i = 0; i < bufferLength / 4; i++){
        initItem(&item);
        pop(B, &item);
    }
    
    // 読み出す
    dumpWithAdv();

    // バッファサイズと同じだけpush
    printf("pop %d item.\n", bufferLength);
    for (unsigned int i = 0; i < bufferLength; i++){
        initItem(&item);
        item.id = i + 10;
        push(B, item);
    }
    
    // 読み出す
    dumpWithAdv();
    dumpWithPop();


    deinitBuffer(B);

    return 0;
}

// advanceを使ってバッファを読み出す
void dumpWithAdv(){
    printf("dump with advanced...\n");
    int status = BUFFER_OK;
    unsigned int index = 0;
    Item item;
    initItem(&item);
    while (status == BUFFER_OK){
        status = getItemAt(B, index, &item);
        if(status == BUFFER_OK){
            printf("item id:%d\n", item.id);
        }
        index++;
    }
    printf("........\n");
}

// popを使ってバッファを読み出す
void dumpWithPop(){
    printf("dump with pop...\n");
    int status = BUFFER_OK;
    unsigned int index = 0;
    Item item;
    initItem(&item);
    while (status == BUFFER_OK){
        status = pop(B, &item);
        if(status == BUFFER_OK){
            printf("item id:%d\n", item.id);
        }
        index++;
    }
    printf("........\n");
}
