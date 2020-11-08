# embedBuffer

## Overview

Generic buffer implement written in C.  
**NOTE:** this repository is **minimized edition** for embedded device.  
Some features such multithreading buffer is shrinked or abolished.

## Latest developing features - dynamic buffer size!

Now, you can define buffer size dynamic!  
memory for new buffer will be allocated with initializer(`initBuffer` in Initialize.c).  
Whenever as long as memory allows, you can define buffer of any size!  

## Usage

### Generate sample program

 1. clone this repository.
 1. `make` to generate sample.

### Embed it to your projects

In details, see `main.c`.  
(New dynamic buffer have significantly changed how to embed it, and this is likely to continue. sorry for ambiguous description.)  

## Licence

All of code in this repository are published under the MIT licence.
