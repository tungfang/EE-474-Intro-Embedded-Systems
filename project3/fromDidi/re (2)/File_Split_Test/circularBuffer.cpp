#include "circularBuffer.h"

// Replaces oldest value in buffer with data.

void pushSampleLong (unsigned int buffer[], unsigned int data, Bool firstHalf) {
  if (firstHalf) {
    pushSample (buffer, data);  
  } else {
    unsigned int curIndex = buffer[BUFFER_INSERT_INDEX_SECOND];
    int size = buffer[BUFFER_SIZE_INDEX_SECOND];
    unsigned int nextIndex = curIndex + 1;

    // Update buffer index for next sample
    if (nextIndex > (size*2 - 1)) {
    nextIndex = BUFFER_FIRST_DATA_INDEX_SECOND;
  }
  buffer[BUFFER_INSERT_INDEX_SECOND] = nextIndex;

  buffer[nextIndex] = data;  
  } 
}

void pushSample (unsigned int buffer[], unsigned int data) {
  unsigned int curIndex = buffer[BUFFER_INSERT_INDEX];

  int size = buffer[BUFFER_SIZE_INDEX];
  unsigned int nextIndex = curIndex + 1;

  // Update buffer index for next sample
  if (nextIndex > (size - 1)) {
    nextIndex = BUFFER_FIRST_DATA_INDEX;
  }
  buffer[BUFFER_INSERT_INDEX] = nextIndex;

  buffer[nextIndex] = data;
  //Serial.print("pushSample successful");
  //Serial.println(buffer[nextIndex]);
}
// Returns Nth previous sample (n >= 0). n = 0 is last sample, n = 1 is prevous sample.
unsigned int getNthPreviousSample (unsigned int buffer[], int n) {
  if (n < 0) {
    printf("getNthPreviousSample: n cannot be negative. Output will be bad.");
  }
  unsigned int curIndex = buffer[BUFFER_INSERT_INDEX];
  unsigned int size = buffer[BUFFER_SIZE_INDEX];
  unsigned int sizeBuffer = size - BUFFER_METADATA_SIZE;
  unsigned int bufferOffset = curIndex - BUFFER_METADATA_SIZE;
  unsigned int nSafe = n % (sizeBuffer); // handles circular case

  unsigned int getIndex = BUFFER_FIRST_DATA_INDEX + ((bufferOffset + (sizeBuffer - nSafe)) % sizeBuffer);

  return buffer[getIndex];
}

// Initalizes indexes and buffer meta data. Must have size >= 4.
void initBuffer(unsigned int buffer[], int size) {
  buffer[BUFFER_SIZE_INDEX] = size;
  buffer[BUFFER_INSERT_INDEX] = 1;
  for (int i = BUFFER_FIRST_DATA_INDEX; i < size; i++) {
    buffer[i] = 0;
  }
  //Serial.print("intiate good\n");
}

void initBufferLong(unsigned int buffer[], int size) {
  buffer[BUFFER_SIZE_INDEX] = size/2;
  buffer[BUFFER_INSERT_INDEX] = 1;
  buffer[BUFFER_SIZE_INDEX_SECOND] = size/2;
  buffer[BUFFER_INSERT_INDEX_SECOND] = 9;
  for (int i = BUFFER_FIRST_DATA_INDEX; i < size/2; i++) {
    buffer[i] = 0;
  }
  for (int i = BUFFER_FIRST_DATA_INDEX_SECOND; i < size; i++) {
    buffer[i] = 0;  
  }
  //Serial.print("intiate good\n");
}

void printBuffer(unsigned int buffer[], int size) {
   // printf("\n");
    for (int i = 0; i < size; i++) Serial.print(buffer[i]);
    Serial.print("\n");
}

// Empty buffer is defined as 0 in index 2 -> size - 1
int isBufferEmpty (unsigned int buffer[], int size) {
    int isEmpty = 1;
    for (int i = BUFFER_FIRST_DATA_INDEX; i < size; i++) {
        if (buffer[i] != 0) {
            isEmpty = 0;
        }
    }
    return isEmpty;
}

unsigned int getCurrentValue(unsigned int buffer[]) {
  unsigned int curIndex = buffer[BUFFER_INSERT_INDEX];
  return buffer[curIndex];
}
