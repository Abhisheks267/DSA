/*Rakesh is a neurosurgeon at Leelavathi Hospital in Mumbai. Every 1st day of the month, he visits Hubballi to look after
 mentally ill patients suffering from brain-related diseases and returns to Mumbai 15th day of the month. He informs his
receptionist to prepare a list of patients with reserved appointments to consult him. Some patients didn’t turn up to
consult the doctor, their details found at specified positions were removed, and an updated list was prepared.
Apply Problem-Solving Framework and write a modular C program to have an updated list of patients.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],place[20];
    int day,month,year;
    struct node *link;
};
struct node* createnode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    printf("Memory not allocated\n");
    else
    {
        scanf("%s%s%d%d%d",newnode->name,newnode->place,&newnode->day,&newnode->month,&newnode->year);
        newnode->link=NULL;
    }
    return newnode;
}
struct node* insertfront(struct node *head)
{
    struct node *newnode;
    newnode=createnode();
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
struct node* display_list(struct node *head)
{
    struct node *cur;
    if(head==NULL)
        printf("List empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%s %s %d %d %d\n",cur->name,cur->place,cur->day,cur->month,cur->year);
            cur=cur->link;
        }
    }
    return head;
}
int count_nodes(struct node *head)
{
   struct node *cur;
    int count=0;
    cur=head;
    while(cur!=NULL)
    {
        count++;
        cur=cur->link;
    }
    return count;
}
struct node* deleteposition(struct node *head,int pos)
{
    struct node *cur=head,*temp=head,*prev=NULL;
   int count=count_nodes(head);
    if(head==NULL)
      return NULL;
    else if(pos==1&&head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else if(pos==1)
    {
        head=head->link;
        free(temp);
    }

    else if(pos>1&&pos<=count)
    {
        cur=head;
        for(int i=1;i<pos;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=cur->link;
        free(cur);
    }
    else
        printf("Position %d does not exist.\n",pos);
    return head;
}
int main() {
 struct node *head=NULL;
    int n,pos,r;
    scanf("%d",&n);
    if(n>=1)
    {
        for(int i=0;i<n;i++)
            head=insertfront(head);
        scanf("%d",&r);
        for(int i=0;i<r;i++)
        {
            scanf("%d",&pos);
            head=deleteposition(head,pos);
        }
        printf("Updated List is:\n");
        display_list(head);
    }
   else
       printf("Invalid input");
    return 0;
}
