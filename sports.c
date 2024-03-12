/*Indian Sports Academy conducting selection trials for young candidates who are willing to participate in Olympics 2022.
 Any candidate between the age group 18 to 35 can participate in the selection process. Indian Sports Academy
 shortlists based on the height of candidates to be selected for next rounds and only one candidate is selected from
 each round. Candidates are allowed to enter on first come first serve basis, but only the candidates with a height
 greater than 185 centimetres will be selected for next round. Given the heights of candidates determine how many
 candidates are not selected for Olympics 2022.*/
 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 50
struct queue
{
    int num[SIZE];
    int front,rear;
};
void enqueue(struct queue *qptr,int data)
{
    if(qptr->rear==SIZE-1)
        printf("Queue overflow");
    else
    {
        qptr->rear++;
        qptr->num[qptr->rear]=data;
    }
}
int dequeue(struct queue *qptr)
{
    if(qptr->front==qptr->rear)
        return -1;
    else
    {
        qptr->front++;
        return qptr->num[qptr->front];
    }
}
void display(struct queue *qptr)
{
    if(qptr->front==qptr->rear)
        printf("Queue Empty\n");
    else
    {
        for(int i=(qptr->front+1);i<=qptr->rear;i++)
            printf("%d ",qptr->num[i]);
    }
}
int not_selected(struct queue *qptr)
{
    int c=0,h;
    while(qptr->front!=qptr->rear)
    {
        h=dequeue(qptr);
        if(h<=185)
            c++;
    }
    return c;
}
int main() {
struct queue q,*qptr=&q;
qptr->rear=qptr->front=-1;
int n,data,c;
scanf("%d",&n);
if(n>0)
{for(int i=0;i<n;i++)
 {
    scanf("%d",&data);
    enqueue(qptr,data);
 }
 c=not_selected(qptr);
 printf("%d",c);
}
  else
      printf("Cannot perform operations");
    return 0;
}
