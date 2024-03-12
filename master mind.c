/*Mastermind is a British television game show. Its creator, Bill Wright, drew inspiration from his experiences of being
asked quiz questions during World War II. The show featured an intimidating setting and challenging quiz questions.
A quiz competition was held for students of Kingsway New Primary School in Manchester, Northwest during Spring. Julia,
 a seventh standard student, has won N number of books in the show. She bought all the books to class and kept them one
 above the other on her table as a single pile of books. She had books mixed up of different subjects. Julia picks book
 of particular subject and counts them. Also she determines total cost of all the books she won. Apply Problem Solving
 Framework and write a modular C program to help Julia.*/
 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char sub[20];
    double price;
    struct node* link;
};
struct node* createnode()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
            printf("Memory not allocated\n");
    else
    {
        scanf("%s%lf",newnode->sub,&newnode->price);
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
            printf("%s %0.2lf\n",cur->sub,cur->price);
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
void checkbook(struct node* top,char sb[20])
{  int c=0;
   double d=0;
   while(top!=NULL)
   {
       if(strcmp(top->sub,sb)==0)
           c++;
       d=d+top->price;
       top=pop(top);
   }
  printf("\n%s books she won: %d\n",sb,c);
  printf("\nTotal cost of all books: %0.2lf",d);
}
int main() {
    struct node *top=NULL;
    char sb[20];
    int n;
    scanf("%d",&n);
    if(n>0)
    {
     for(int i=0;i<n;i++)
         top=push(top);
      scanf("%s",sb);
     printf("Stack of books is:\n");
        display_stack(top);
      checkbook(top,sb);
    }
    else
        printf("Invalid input");

    return 0;
}

