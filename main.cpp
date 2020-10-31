/*
 * Buffer.hをC++に対応させる
*/
#include "Buffer.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // キュー初期化
    Buffer buffer, *Q;
    Q = &buffer;
    initBuffer(Q);

    // 適当なアイテムを追加してenBuffer
    char strBuffer[8] = "enBuffer";
    Item item;
    item.id = 12;
    memcpy(item.data, strBuffer, 8);
    enBuffer(Q, item);

    // deBufferして値を読む
    char dumpstrBuffer[256];
    memset(dumpstrBuffer, 0, 35);
    Item debufferItem;
    deBuffer(Q, &debufferItem);
    dumpItem(&debufferItem, dumpstrBuffer);

    printf("%s\n", dumpstrBuffer);

    return 0;
}
