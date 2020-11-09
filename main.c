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
    lockBuffer(B); // To call this, buffer will refuse to slice old data
    Item item;
    for (int i = 0; i < bufferLength + 20; i++){
        initItem(&item);
        item.id = i;
        printf("%d ", i);
        printf("result: %d\n", push(B, item));
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
