#include"stack.h"
#include"queue.h"
int main(){
    stack s;
    Stack_Init(&s,10);
    Stack_IsEmpty(&s);
    Stack_Isfull(&s);
    float value =10.33f;float value1=0.0f;
    Stack_EnStack(&s,&value,sizeof(value));
    Stack_DeStack(&value1,&s,sizeof(value1));
    Stack_Free(&s);
    printf("hello world\n");
   queue q;
   Queue_Init(&q); 
   Queue_IsEmpty(&q);
   Queue_Isfull(&q);
   for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) {
    
        Queue_Enqueue(&q, i);
}

    int value2;
    Queue_Dequeue(&q, &value2);
  for (int i = 0; i <MAX_QUEUE_SIZE ; i++)
   {
     printf("%d", q.data[i]);
   }
   printf("%d %d", q.front, q.rear);
   return 0; 
}
