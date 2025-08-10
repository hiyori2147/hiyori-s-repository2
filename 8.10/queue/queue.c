#include"queue.h"
void Queue_Init(queue*q){
    q->front=0;
    q->rear=0;
    for(int i=0;i<MAX_QUEUE_SIZE;i++)
        q->data[i]=0;
}
bool Queue_IsEmpty(queue*q){
    return q->front==q->rear;
}
bool Queue_Isfull(queue*q){
    return (q->rear+1)%MAX_QUEUE_SIZE==q->front;
}
bool Queue_Enqueue(queue*q,int value){
    if(Queue_Isfull(q)){
        return false;//队列为满
    }
    q->data[q->rear]=value;
    q->rear=(q->rear+1)%MAX_QUEUE_SIZE;//循环队列
}
bool Queue_Dequeue(queue*q,int*value){
    if (Queue_IsEmpty(q))
    {
        return false;//队列为空
    }
    *value=q->data[q->front];
    q->front=(q->front+1)%MAX_QUEUE_SIZE;//循环队列
    void free(void *ptr);
}
