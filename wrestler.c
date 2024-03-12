/*A new game is introduced in the World Wrestling Event, wherein the competition is conducted across Countries. King is
1st player representing country Oman and Sultan 2nd player representing country India. In the game, there is a circle
with N points and initially, 1 dumble of weight W is placed at each point.The mind game here is that now the player has
to pick a chit which represents K. If the weight is a modulus of K and is greater than the previous dumble, only then he
has to lift the dumble and that particular weight is added to the dumble score. Each time the player jumps to next dumble
,the crew boy removes the current dumble. Find whose dumble score is highest.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *link;
};
struct queue* create()
{
    struct queue *newnode=NULL;
    newnode=(struct queue*)malloc(sizeof(struct queue));
    scanf("%d",&newnode->data);
    newnode->link=newnode;
    return newnode;
}
struct queue* enqueue(struct queue *front)
{
    struct queue *cur=NULL,*newnode=NULL;
    newnode=create();
    if(front==NULL)
        front=newnode;
    else
    {
        cur=front;
        while(cur->link!=front)
            cur=cur->link;
        cur->link=newnode;
        newnode->link=front;
    }
    return front;
}
struct queue* dequeue(struct queue *front)
{
    struct queue *temp=NULL,*cur=NULL;
    if(front==NULL)
        return NULL;
    else if(front->link==front)
    {
        free(front);
        front=NULL;
    }
    else
    {   cur=front;
        while(cur->link!=front)
            cur=cur->link;
        cur->link=front->link;
        temp=front;
        front=front->link;
        free(temp);
    }
    return front;
}
void winner(struct queue *front,int k1,int k2)
{
    int st=0,kt=0,prev1=0,prev2=0;
    while(front!=NULL)
    {
        if(front->data % k1 == 0 && front->data > prev1)
        {
            kt+=front->data;
            prev1=front->data;
        }
        if(front->data % k2 == 0 && front->data > prev2)
        {
             st+=front->data;
             prev2=front->data;
        }
        front=dequeue(front);
    }
    printf("%d\n",kt);
    printf("%d\n",st);
    if(kt>st)
        printf("The winner is King.");
    else
        printf("The winner is Sultan.");
}
int main() {
struct queue *front=NULL;
    int n=0,m=0,k1=0,k2=0;
    scanf("%d%d%d%d",&n,&m,&k1,&k2);
    if(n>0)
    {
        for(int i=0;i<n;i++)
            front=enqueue(front);
        winner(front,k1,k2);
    }

    return 0;
}
