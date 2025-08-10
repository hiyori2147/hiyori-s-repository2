#ifndef QUEUE_H
#define QUEUE_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<string.h>
#define MAX_QUEUE_SIZE 5
typedef struct Oueue{
    int data[MAX_QUEUE_SIZE];
    uint8_t front;
    uint8_t rear;
}queue;
void Queue_Init(queue*q);
bool Queue_IsEmpty(queue*q);
bool Queue_Isfull(queue*q);
bool Queue_Enqueue(queue*q,int value);
bool Queue_Dequeue(queue*q,int* value);
#endif 
