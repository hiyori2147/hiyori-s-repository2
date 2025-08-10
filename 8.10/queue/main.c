#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"queue.h"
int main(){
   queue q;
   Queue_Init(&q); 
   Queue_IsEmpty(&q);
   Queue_Isfull(&q);
   for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) {
    
        Queue_Enqueue(&q, i);
}

   int value ;
    Queue_Dequeue(&q, &value);
  for (int i = 0; i <MAX_QUEUE_SIZE ; i++)
   {
     printf("%d", q.data[i]);
   }
   printf("%d %d", q.front, q.rear);
   return 0; 
}