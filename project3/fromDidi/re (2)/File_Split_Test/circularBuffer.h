#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include "bool.h"
#include <Arduino.h>

#define BUFFER_SIZE_INDEX 0 // Index of array that stores size
#define BUFFER_SIZE_INDEX_SECOND 8 //Index of array that store size for second part
#define BUFFER_INSERT_INDEX 1 // Location to put next sample
#define BUFFER_INSERT_INDEX_SECOND 9 // Location to put next sample for second part
#define BUFFER_FIRST_DATA_INDEX 2 // First valid data index
#define BUFFER_FIRST_DATA_INDEX_SECOND 10 // First valid data index for second part
#define BUFFER_METADATA_SIZE 2 // amount of indexes for buffers


// int curIndex;
//unsigned int nextIndex;

void pushSampleLong (unsigned int buffer[], unsigned int data, Bool firstHalf);
void pushSample (unsigned int buffer[], unsigned int data);
unsigned int getNthPreviousSample (unsigned int buffer[], int n);
void initBuffer(unsigned int buffer[], int size);
void initBufferLong(unsigned int buffer[], int size);
void printBuffer(unsigned int buffer[], int size);
int isBufferEmpty (unsigned int buffer[], int size);
unsigned int getCurrentValue(unsigned int buffer[]);

#endif // CIRCULAR_BUFFER_H
