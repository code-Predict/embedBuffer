/*
 * 単体テスト
*/
#include <stdio.h>
#include "Buffer.h"

//
Buffer buffer, *B;

int main(int argc, char *argv[]) {
    // buffer初期化
    unsigned int bufferLength = 50;
    B = &buffer;
    initBuffer(B, bufferLength);

    printf("size: %d\n", buffer.size);

    // push
    printf("pushing...\n");
    Item item;
    for (int i = 0; i < bufferLength + 20; i++){
        initItem(&item);
        item.id = i;
        printf("%d\n", i);
        push(B, item);
    }

    // pop
    printf("poping...\n");
    int status = BUFFER_OK;
    Item popItem;
    char buf[300];
    while (status == BUFFER_OK){
        status = pop(B, &popItem);
        if(status == BUFFER_OK){
            printf("%d\n", popItem.id);
        }
    }

    deinitBuffer(B);

    return 0;
}
