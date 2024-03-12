/*Simran is fond of smart watches and purchases a new smart watch as soon as it is launched in the market. She collects
 N watches of different brands and maintains their details in the list. She wears a different watch every day; once the
 last watch she wears, she repeats wearing the first watch. One day, Simran found that P watches were outdated, which
 she had bought in a particular year, and she removed them from her list.
Apply problem-solving framework and write a modular C program to maintain an updated list of watches with Simran.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],model[20];
    int year;
    struct node *link;
};
struct node* createnode()
{
    struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory not allocated");
    else
    {
        scanf("%s%s%d",newnode->name,newnode->model,&newnode->year);
        newnode->link=newnode;
    }
    return newnode;
}
struct node* insertendcsll(struct node *head)
{
    struct node *cur=NULL,*newnode=NULL;
    newnode=createnode();
    if(head==NULL)
    {
        head=newnode;
        head->link=head;
    }
    else
    {
        cur=head;
        while(cur->link!=head)
            cur=cur->link;
        cur->link=newnode;
        newnode->link=head;
    }
    return head;
}
struct node* deleteoutdated(struct node *head,int Y)
{
     struct node *cur=head,*temp=head,*prev=head;
    int s=0;
    if(head==NULL)
        return NULL;
     else if(head->link==head&&head->year==Y)
     {    s=1;
         free(head);
         head=NULL;
     }
    else if(head->year==Y)
    {   s=1;
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
            if(cur->year==Y)
            {
                s=1;
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
void displaycsll(struct node *head)
{
    struct node *cur=head;
    if(head==NULL)
        printf("Empty.\n");
    else
    {
        do
        {
             printf("%s %s %d\n",cur->name,cur->model,cur->year);
             cur=cur->link;
        }
        while(cur!=head);
    }
}
int main() {
struct node *head=NULL;
    int N,P,Y;
    scanf("%d",&N);
    if(N>0)
     {
        for(int i=0;i<N;i++)
            head=insertendcsll(head);
        scanf("%d%d",&P,&Y);
            for(int i=0;i<P;i++)
            head=deleteoutdated(head,Y);
        printf("Updated watches list:\n");
        displaycsll(head);
    }
    else
     printf("Invalid input");
    return 0;
}
