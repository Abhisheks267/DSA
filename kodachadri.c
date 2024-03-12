/*A development team in TCS plans a trekking trip to Kodachadri. The trip admin keeps track of people joining the trip.
After few days, K people drop out whose names appear at the beginning in the list and L new people gets added.
Help the trip admin to check the total number of people ready for the trip and create a final list.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],town[20];
    long no;
    struct node *link;
};
struct node* create()
{
    struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("no memory allocated");
    else
    {
        scanf("%s%s%ld",newnode->name,newnode->town,&newnode->no);
        newnode->link=newnode;
    }
    return newnode;
}
struct node* insertendcsll(struct node *head,struct node *newnode)
{
   struct node *cur=head;
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
    struct node *cur=NULL;
    if(head==NULL)
        printf("Empty.\n");
    else
    {cur=head;
        do
        {
            printf("%s %s %ld\n",cur->name,cur->town,cur->no);
            cur=cur->link;
        }
        while(cur!=head);
    }
}
struct node* dropout(struct node *head)
{
    struct node *cur=head,*temp=head;
    if(head==NULL)
        return NULL;
    else if(head->link==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        while(cur->link!=head)
            cur=cur->link;
        cur->link=head->link;
        head=head->link;
        free(temp);
    }
    return head;
}
int countnodes(struct node *head)
{struct node *cur=head;
    int count=0;
    if(head==NULL)
        return count;
    else
    { do
        {
            count++;
            cur=cur->link;
        }
        while(cur!=head);
    }
    return count;
}
struct node* joinlist(struct node *head,struct node *list)
{
    struct node *cur=NULL;
    if(head==NULL&&list==NULL)
        return NULL;
    else if(head==NULL)
        return list;
    else if(list==NULL)
        return head;
    else
    {
        cur=head;
        while(cur->link!=head)
            cur=cur->link;
            cur->link=list;
        cur=list;
        while(cur->link!=list)
            cur=cur->link;
        cur->link=head;
    }
    return head;
}
int main() {
struct node *head=NULL,*list=NULL,*newnode=NULL;
    int n,k,l,count=0;
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0;i<n;i++)
        {
            newnode=create();
            head=insertendcsll(head,newnode);
        }
        scanf("%d",&k);
       for(int i=0;i<k;i++)
           head=dropout(head);
        printf("List after drop out:\n");
        displaycsll(head);
        printf("\nList after new additions:\n");
        scanf("%d",&l);
        for(int i=0;i<l;i++)
        {
            newnode=create();
            list=insertendcsll(list,newnode);
        }
        head=joinlist(head,list);
         displaycsll(head);
        count=countnodes(head);
        printf("\nTotal people going on trip is: %d",count);
    }
    else
        printf("Invalid input");
    return 0;
}
