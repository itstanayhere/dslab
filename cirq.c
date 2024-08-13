#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueue(struct Queue *q, int item)
{
    if((q->r+1)%q->size==q->f)
    {
        printf("Queue is full\n");
        return;
    }
    q->r=((q->r)+1)%(q->size);
    q->arr[q->r]=item;
}
void dequeue(struct Queue *q)
{
    if(q->f==q->r)
    {
        printf("Queue is empty\n");
        return;
    }
    q->f=(q->f+1)%q->size;
    printf("Element dequeued=%d\n",q->arr[q->f]);
}
void show(struct Queue *q)
{
    printf("\n");
    if(q->r==q->f)
    {
        printf("Queue is empty\n");
        return;
    }
    int fr=(q->f+1)%q->size;
    while(fr!=((q->r+1)%q->size))
    {
        printf("%d\n",q->arr[fr]);
        fr=(fr+1)%q->size;
    }
}
int main()
{
    struct Queue q;
    q.size=5;
    q.f=0;
    q.r=0;
    q.arr=(int*)malloc((q.size)*sizeof(int));
    enqueue(&q,5);
    enqueue(&q,10);
    enqueue(&q,15);
    enqueue(&q,20);
    dequeue(&q);
    show(&q);

}
