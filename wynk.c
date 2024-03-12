/*Sham uses Wynk online music player as he is fond of listening to music. However, he also wants to develop an offline
music player where he can add the songs and delete the songs from the player. He wants to have a music player to:
Display all the songs which are sung by a particular singer. Delete the particular song by song name.
NOTE: Each song details are: song name, singer name, duration (mm.ss) and year.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char sname[25],singer[20];
    float time;
    int year;
    struct node *rlink,*llink;
};
struct node* create()
{
    struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory empty.");
    else
    {
        scanf("%s%s%f%d",newnode->sname,newnode->singer,&newnode->time,&newnode->year);
        newnode->rlink=newnode;
        newnode->llink=newnode;
    }
    return newnode;
}
struct node* insertendcdll(struct node *head)
{
     struct node *last=NULL,*newnode=NULL;
    newnode=create();
    if(head==NULL)
        head=newnode;
    else
    {
        last=head->llink;
        last->rlink=newnode;
        newnode->rlink=head;
        head->llink=newnode;
        newnode->llink=last;
    }
    return head;
}
void displaycdll(struct node *head)
{
    struct node *cur=head;
    if(head==NULL)
        printf("Empty.");
    else
    {
        do
        {
            printf("%s %s %0.2f %d\n",cur->sname,cur->singer,cur->time,cur->year);
            cur=cur->rlink;
        }
        while(cur!=head);
    }
}
void searchsong(struct node *head,char name[20])
{
    struct node *cur=head;
    int s=0;
    if(head==NULL)
         printf("Empty.");
    else
    {
        do
        {   if(strcmp(cur->singer,name)==0)
           {
             s=1;
             printf("%s %s %0.2f %d\n",cur->sname,cur->singer,cur->time,cur->year);
           }
            cur=cur->rlink;
        }
        while(cur!=head);
    }
    if(s==0)
        printf("No songs of %s to display\n",name);
}
struct node* deletesong(struct node *head,char song[25])
{
    struct node *cur=NULL,*prev=NULL,*next=NULL,*temp=head,*s=NULL;
    int st=0;
    if(head==NULL)
        return NULL;
    else if(head->rlink==head)
    {
        if(strcmp(head->sname,song)==0)
        {
            st=1;
            printf("\nDeleted %s %s %0.2f %d",head->sname,head->singer,head->time,head->year);
            free(head);
            head=NULL;
        }
    }
    else if(strcmp(head->sname,song)==0)
    {  st=1;
        printf("\nDeleted %s %s %0.2f %d",head->sname,head->singer,head->time,head->year);
        cur=head->llink;
        next=head->rlink;
        cur->rlink=next;
        next->llink=cur;
        head=next;
        free(temp);
    }
    else if(strcmp(head->llink->sname,song)==0)
    {   st=1;
        cur=head->llink;
        printf("\nDeleted %s %s %0.2f %d",cur->sname,cur->singer,cur->time,cur->year);
        prev=cur->llink;
        prev->rlink=head;
        head->llink=prev;
        free(cur);
    }
    else
    {
        cur=head->rlink;
        while(cur!=head)
        {   if(strcmp(cur->sname,song)==0)
            {
             st=1;
             printf("\nDeleted %s %s %0.2f %d",cur->sname,cur->singer,cur->time,cur->year);
             prev=cur->llink;
             next=cur->rlink;
             prev->rlink=next;
             next->llink=prev;

             free(cur);
             break;
            }
            cur=cur->rlink;
        }

    }
    if(st==0)
        printf("\nNo song %s to delete",song);
    return head;
}
int main() {
struct node *head=NULL;
char name[20],song[25];
int n;
scanf("%d",&n);
if(n>0)
{
    for(int i=0;i<n;i++)
     head=insertendcdll(head);
    displaycdll(head);
    scanf("%s",name);
    printf("\n");
    searchsong(head,name);
    scanf("%s",song);
    head=deletesong(head,song);
}
else
   printf("Invalid input.");
    return 0;
}
