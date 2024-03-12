/*Frankinson has N number of coins in his pocket. Coins are of denominations of 1, 2, 5 and 10. He keeps all the coins on
 the table one above the other. Then he picks out one coin at a time and counts them of specific denomination.
 Help Frankinson to count the coins of all the different denominations.*/
 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int no;
    struct node *link;
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
void coins(struct node* top)
{
   int c1=0,c2=0,c5=0,c10=0;
    while(top!=NULL)
    {
     if(top->no==1)
        c1++;
     else if(top->no==2)
        c2++;
     else if(top->no==5)
         c5++;
     else
       c10++;
     top=pop(top);
    }
    printf("\nDenomination 1 coins: %d\n",c1);
    printf("Denomination 2 coins: %d\n",c2);
    printf("Denomination 5 coins: %d\n",c5);
    printf("Denomination 10 coins: %d\n",c10);
}
int main() {
    struct node *top=NULL;
    int n;
    scanf("%d",&n);
    if(n>0)
    {
     for(int i=0;i<n;i++)
        top=push(top);
      printf("Coins in Stack are:\n");
        display_stack(top);
       coins(top);
    }
    else
        printf("No coins.");

    return 0;
}

