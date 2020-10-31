# Buffer

## Overview

Generic buffer implement written in C.(It supports multi-thread buffer using pthread and mutex.)  

## Usage

 1. clone this repository.
 1. `make` to generate `Buffer.dll`. (If you only make `Buffer.h`, you can use `make Buffer.dll`.)

### How to embed it to your projects

If you use buffer with single-thread system, you only need include `Buffer.h`.  
But, buffer will be used with multi-thread system generally. In this case, you need include `BufferThreads.h` additional.  

## Licence

All of code in this repository are published under the MIT licence.
