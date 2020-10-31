/*
 * バッファ
*/
#include <stdio.h>
#include "Buffer.h"

int main(int argc, char const *argv[]) {
    // キュー初期
    Buffer buffer, *Q;
    Q = &buffer;
    initBuffer(Q);

    // いくつかpush
    Item eqItem;
    for(int i = 0; i < 10; i++){
        printf("push: %d\n", i);
        eqItem.id = i;
        push(Q, eqItem);
    }

    // 空になるまでpop
    Item dqItem;
    int status = BUFFER_OK;
    char strBuffer[100];
    memset(strBuffer, 0, 100);
    while (status != BUFFER_EMPTY) {
        status = pop(Q, &dqItem);
        dumpItem(&dqItem, strBuffer);
        printf("%s\n", strBuffer);
    }

    deinitBuffer(Q);
    return 0;
}