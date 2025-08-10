#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<string.h>
#include <stddef.h>
typedef struct Stack{
    char *base;//栈底指针
    char *top;//栈顶指针
    uint32_t size;//栈的大小
}stack;
void Stack_Init(stack*q,uint32_t z);
bool Stack_IsEmpty(stack*q);
bool Stack_Isfull(stack*q);
bool Stack_EnStack(stack*q,void * value,uint32_t size);
bool Stack_DeStack(void* value,stack*q,uint32_t size);
void Stack_Free(stack *s);
#endif // STACK_H