#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void Stack_Init(stack *s, uint32_t z){
    s->base=(char*)malloc(z*sizeof(char));
    s->top=s->base;
    s->size=z;
}
bool Stack_IsEmpty(stack *s){
    return s->top == s->base;
}
bool Stack_Isfull(stack *s){
    return (s->top - s->base) >= s->size;
}
bool Stack_EnStack(stack *s, void *value,uint32_t size){
    if(Stack_Isfull(s)){
        return false; }// 栈  
    s->top -= size;
    memcpy(s->top,value,size);
}    
bool Stack_DeStack(void *value,stack *s,uint32_t size){
    if(Stack_IsEmpty(s)){
        return false; // 栈空
    }
    memcpy(value,s->top,size);
    s->top += size;
} 
void Stack_Free(stack *s){
    free(s->base);
    s->base = NULL;
    free(s->top);
    s->top = NULL;
        free(s); 
}
