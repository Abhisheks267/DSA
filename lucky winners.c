/*Reliance Gold Jewels shop in Urban Oasis Mall gives a LUCKY COUPON to all its N customers who visit the shop. The LUCKY
 COUPON has an integer random REGISTERED NUMBER written on it. The shop keeps the entire N given COUPONS one above
 another and staple them. To be the winner of the lucky coupons contest, the REGISTERED NUMBER should be divided by a
 MAGICAL NUMBER, M.On the day of announcement of LUCKY WINNERS the shop opens the stapled coupons one by one and its
 REGISTERED NUMBER will be divided by the M. If the REGISTERED NUMBER is divided by M then that customer will be
 announced as winner by displaying W, otherwise that customer will be announced as loser by displaying L. Finally the
 shop announces number of winners and number of losers.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int no;
    struct node* link;
};
struct node* createnode()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
            printf("Memory not allocated\n");
    else
    {
        scanf("%d",&newnode->no);
        newnode->link=NULL;
    }
    return newnode;
}
struct node* push(struct node *top)
{
    struct node *newnode;
    newnode=createnode();
    if(top==NULL)
        top=newnode;
    else
    {
        newnode->link=top;
        top=newnode;
    }
    return top;
}
void display_stack(struct node *top)
{
    struct node *cur;
    if(top==NULL)
        printf("List empty\n");
    else
    {
        cur=top;
        while(cur!=NULL)
        {
            printf("%d\n",cur->no);
            cur=cur->link;
        }
    }
}
struct node* pop(struct node *top)
{
    struct node *cur;
    if(top==NULL)
        printf("List is empty\n");
    else if(top->link==NULL)
    {
        free(top);
        top=NULL;
    }
    else
    {
        cur=top;
        top=top->link;
        free(cur);
    }
    return top;
}
void checklot(struct node* top,int k)
{  int w=0,l=0;
    while(top!=NULL)
    {
     if(top->no%k==0)
     {
         printf("W ");
         w++;
     }
     else
     {
         printf("L ");
         l++;
     }
     top=pop(top);
    }
    printf("\nNo of winners=%d\n",w);
    printf("No of losers=%d",l);
}
int main() {
    struct node *top=NULL;
    int n,k;
    scanf("%d%d",&n,&k);
    if(n>0&&k>0)
    {
     for(int i=0;i<n;i++)
        top=push(top);
      checklot(top,k);
    }
    else
        printf("Invalid number of customers");
    return 0;
}
