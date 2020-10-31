/*
 * 
*/
#ifndef EQTHREAD_H
#define EQTHREAD_H

/* -------- */
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <unistd.h>
#include "Buffer.h"

/* -------- */
void *enBufferThread(void *_conf);
void *deBufferThread(void *_conf);

#endif