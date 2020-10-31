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

    // 適当なアイテムを追加してpush
    char strBuffer[8] = "push";
    Item item;
    item.id = 12;
    memcpy(item.data, strBuffer, 8);
    push(Q, item);

    // popして値を読む
    char dumpstrBuffer[256];
    memset(dumpstrBuffer, 0, 35);
    Item popItem;
    pop(Q, &popItem);
    dumpItem(&popItem, dumpstrBuffer);

    printf("%s\n", dumpstrBuffer);

    return 0;
}
