/*Shrirish is student participating in coding competition held by KPIT company. He is given a problem statement
“Candy Wending Machine”. A machine will request the selected coins to be inserted, they are 1re, 5rs, 10rs and 20rs coins
 only. When the value of a coin inserted is other than mentioned coins, those coins are returned by the machine.
If the sum of all coins is greater than or equal to 25rs but less than 34rs then fetch Mango Candy from machine, if the
sum of all the coins is greater than or equal to 35rs but less than 49rs then fetch Strawberry Candy, if the sum of all
the coins is greater than or equal to 50rs but less than 70rs fetch Pista Candy, otherwise display No candy.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int no;
    struct node *link;
};
struct node* create()
{
    struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->no);
    newnode->link=NULL;
    return newnode;
}
struct node* enqueue(struct node *front)
{
    struct node *newnode=NULL,*cur=NULL;
    newnode=create();
    if(front==NULL)
        front=newnode;
    else
    {
        cur=front;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    return front;
}
struct node* dequeue(struct node *front)
{   struct node *temp=NULL;
    if(front==NULL)
        printf("Empty");
    else if(front->link==NULL)
    {
        free(front);
        front=NULL;
    }
    else
    {
        temp=front;
        front=front->link;
        free(temp);
    }
   return front;
}
void candy(struct node* front)
{
    int s=0;
    while(front!=NULL)
    {
        if(front->no==1||front->no==5||front->no==10||front->no==20)
           {
            s+=front->no;
           }
        front=dequeue(front);
    }
    if(s>=25 && s<34)
        printf("Mango candy\n");
    else if(s>=35 && s<49)
        printf("Strawberry candy\n");
    else if(s>=50 && s<70)
        printf("Pista candy\n");
    else
        printf("No candy\n");
}
int main() {
struct node *front=NULL;
    int n;
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0;i<n;i++)
            front=enqueue(front);
        candy(front);
    }
    else
        printf("Invalid input");

    return 0;
}
