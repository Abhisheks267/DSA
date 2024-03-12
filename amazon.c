/*Amazon Logistics (AMZL) delivers packages and smileys to Amazon customers every day. On the occasion of the Dussehra
and Diwali festivals, the amazon has launched Amazon Great Indian Festival.
To cope with the large number of orders, delivery associate prepares the list of orders based on location.
Every time he finds a new packet he adds details at the end of the list. A delivery associate will deliver packets to
specified address. Everyday, delivery associate starts distribution of the orders at 10.00 am in the Lingarajnagar colony
 (in the order, houses are connected) and returns to the stock office at 5.00 pm.
Before submitting the summary to the manager he will calculate the amount collected from delivered packets. End of the
day he removes the packet where the price is less than 500*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],month[20];
    int hno,date,year;
    float amt;
    struct node *link;
};
struct node* create()
{
   struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory not allocated");
    else
    {
        scanf("%s%d%d%s%d%f",newnode->name,&newnode->hno,&newnode->date,newnode->month,&newnode->year,&newnode->amt);
        newnode->link=newnode;
    }
    return newnode;
}
struct node* insertendcsll(struct node *head)
{
   struct node *cur=head;
    struct node *newnode=create();
    if(head==NULL)
        head=newnode;
    else
    {
        while(cur->link!=head)
            cur=cur->link;
        cur->link=newnode;
         newnode->link=head;
    }
    return head;
}
void displaycsll(struct node *head)
{
    struct node *cur=head;
    if(head==NULL)
        printf("Empty.");
    else
    {
        do
        {
            printf("%s %d %d %s %d %0.2f\n",cur->name,cur->hno,cur->date,cur->month,cur->year,cur->amt);
            cur=cur->link;
        }
        while(cur!=head);
    }
}
float totalamt(struct node *head)
{
   struct node *cur=head;
    float amount=0;
    if(head==NULL)
        printf("Empty.");
    else
    {
        do
        {
            amount=amount+cur->amt;
            cur=cur->link;
        }
        while(cur!=head);
    }
    return amount;
}
struct node* deleteorder(struct node *head)
{
  struct node *cur=head,*temp=head,*prev=head;
    int s=0;
    if(head==NULL)
        return NULL;
     else if(head->link==head&&head->amt<500)
     {    s=1;
         printf("%s %d %d %s %d %0.2f\n",head->name,head->hno,head->date,head->month,head->year,head->amt);
         free(head);
         head=NULL;
     }
    else if(head->amt<500)
    {   s=1;
      printf("%s %d %d %s %d %0.2f\n",head->name,head->hno,head->date,head->month,head->year,head->amt);
        while(cur->link!=head)
            cur=cur->link;
        cur->link=head->link;
        head=head->link;
        free(temp);
    }
    else
    {
        cur=head;
        do
        {
            if(cur->amt<500)
            {
                s=1;
                printf("%s %d %d %s %d %0.2f\n",cur->name,cur->hno,cur->date,cur->month,cur->year,cur->amt);
              break;
            }
            prev=cur;
            cur=cur->link;
        }
        while(cur!=head);

     if(s==0)
        return head;
     else
     {

        prev->link=cur->link;
        free(cur);
     }
    }
     return head;

}
int main() {
struct node *head=NULL;
    float amount;
    int n;
    scanf("%d",&n);
    if(n>0)
     {
        for(int i=0;i<n;i++)
       head=insertendcsll(head);
        amount=totalamt(head);
        printf("Total amount: Rs.%0.2f\n",amount);
        printf("\nDeleted order:\n");
        head=deleteorder(head);
        printf("\nFinal orders list:\n");
        displaycsll(head);
    }
    else
     printf("Invalid input");

    return 0;
}
