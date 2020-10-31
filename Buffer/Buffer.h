/*
 * FIFOキュー 
*/
#ifndef _BUFFER_H_
#define _BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* -------- */
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <errno.h>
#include <sys/time.h>

#define NDEBUG

#define BUFFER_SIZE 100000

#define BUFFER_OK 0
#define BUFFER_FULL 1
#define BUFFER_EMPTY 2

#ifndef uint8_t
    #define uint8_t unsigned char
#endif

/* -------- */
typedef struct item {
    int id;
    uint8_t data[8];
} Item;

typedef struct buffer {
    // Data
    Item data[BUFFER_SIZE + 1];
    int head;
    int tail;
    int length;

    // Thread
    pthread_mutex_t mutex;

    pthread_cond_t isNotEmpty;
    pthread_cond_t isNotFull;

    pthread_cond_t isDebufferFinished;
    pthread_cond_t isEnbufferFinished;

} Buffer;

typedef struct bufferconf {
    Buffer* Q;
    int timeout;
    int* endReq;

} BufferConf;


/* -------- */

// Initializer.c
int initBuffer(Buffer* buffer);
int deinitBuffer(Buffer* buffer);
void initItem(Item *item);

// Dump.c
void dumpItem(Item *item, char* strBuffer);
void dumpBuffer(Buffer *buffer, char* strBuffer);
void dumpu8Array(uint8_t *data, int length, char *strBuffer);

// Operate.c
int enBuffer(Buffer* buffer, Item item);
int deBuffer(Buffer* buffer, Item* item);

//MTSOperate.c
int enBufferMT(Buffer* buffer, Item item);
int deBufferMT(Buffer* buffer, Item* item);
int waitForenBuffer(Buffer* buffer, int timeout);
int waitFordeBuffer(Buffer* buffer, int timeout);
void calcTimeSpec(struct timespec* ts, int timeout);
int waitSignal(pthread_mutex_t* mutex, pthread_cond_t* cond, struct timespec* ts);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BUFFER_H_ */