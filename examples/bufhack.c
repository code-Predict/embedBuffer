/*
 * バッファの任意位置の値を取得
*/
#include <stdio.h>
#include "Buffer.h"

Buffer buffer, *B;

int main(int argc, char const *argv[]){
    // buffer初期化
    unsigned int bufferLength = 20;
    B = &buffer;
    initBuffer(B, bufferLength);

    // 適当にpush
    printf("pushing...\n");
    Item item;
    for (int i = 0; i < bufferLength; i++){
        initItem(&item);
        item.id = i;
        push(B, item);
    }
    
    // 適当にpop
    printf("poping...\n");
    for (int i = 0; i < 5; i++){
        Item popItem;
        pop(B, &popItem);
    }
    
    // headを直接弄らず、任意値を加算した値をインデックスとする
    for (int i = 0; i < 20; i++){
        // sizeとのmodをとることでオーバーランを防止
        // ただこれだとtailが動いた(=pushした)時に困るんよ
        int index = (buffer.head + i) % buffer.size;
        
        Item popItem = buffer.data[index];
        char buf[300];
        dumpItem(&popItem, buf);
        printf("%s\n", buf);
    }

    return 0;
}

