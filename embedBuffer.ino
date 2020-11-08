/*
 * ESP32でバッファを動かせるようにする 
*/
#include "Buffer.h"

Buffer buffer, *B;

void setup(){
    Serial.begin(115200);

    // バッファ初期化
    B = &buffer;
    initBuffer(B);
}

void loop(){
    // バッファサイズ+20回push
    Serial.println("Pushing...");
    Item pushItem;
    for (int i = 0; i < buffer.length + 20; i++) {
        pushItem.id = i;
        push(B, pushItem);
        Serial.println(pushItem.id);
    }

    delay(2000);

    // なくなるまでpop
    Serial.println("Poping...");
    int status = BUFFER_OK;
    while (status != BUFFER_EMPTY) {
        Item popItem;
        status = pop(B, &popItem);
        if(status == BUFFER_OK){
            Serial.println(popItem.id);
        }
    }

    delay(10000);
}

