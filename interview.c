/*Continental Softwares Pvt. Ltd., conducted an Interview for pre-final year candidates in the month of March 2023.
N candidates were shortlisted for interview from the School of Computer Science Engineering. There were 2 rounds in the
Interview process, written test and technical interview round. The company eliminated 1 candidate who scored lowest in
the written test. Then, the company eliminated 1 candidate with particular name.

The final list was announced by the Continental Softwares offering a 10 lacs salary package for 1 candidate who had
 scored highest marks in technical round.
 */
 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],cname[20],pgm[20];
    int tm,techm;
    struct node *link;
};
struct node* createnode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory not allocated");
    else
    {
        scanf("%s %s %s %d %d",newnode->name,newnode->cname,newnode->pgm,&newnode->tm,&newnode->techm);
        newnode->link=NULL;
    }
    return newnode;
}
struct node* insert_end(struct node *head)
{
    struct node *newnode,*cur;
    newnode=createnode();
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
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
            printf("%s %s %s %d %d\n",cur->name, cur->cname, cur->pgm, cur->tm, cur->techm);
            cur=cur->link;
        }
    }
    return head;
}
struct node* lowestmarks(struct node *head)
{
    struct node *cur=head,*low=NULL,*prev=NULL,*prevlow=NULL;
    int min=999;
    if(head==NULL)
        printf("List empty\n");
    else
    {
     while(cur!=NULL)
     {
       if(cur->tm<min)
       {
           min=cur->tm;
           prevlow=prev;
           low=cur;
       }
        prev=cur;
        cur=cur->link;
     }
        if(low==head)
      {
        head=head->link;
        free(low);
      }
     else
     {
        prevlow->link=low->link;
         free(low);
     }

    }
    return head;
}
struct node* dname(struct node *head,char keyname[20])
{
    struct node *cur=head,*kn=NULL,*prev=NULL,*prevkn=NULL;
    int status=0;
    if(head==NULL)
        printf("List empty\n");
    else
    {
     while(cur!=NULL)
     {
       if(strcmp(cur->name,keyname)==0)
       {   status=1;
           prevkn=prev;
           kn=cur;
           break;
       }
        prev=cur;
        cur=cur->link;
     }
        if(status==1)
    {
        if(kn==head)
      {
        head=head->link;
        free(kn);
      }
     else
     {
        prevkn->link=kn->link;
         free(kn);
     }
        }
     else
         printf("name not found\n");
    }
    return head;
}
struct node* highestmarks(struct node *head)
{
    struct node *cur=head,*high=NULL;
    int max=-1;
    if(head==NULL)
        printf("List empty\n");
    else
    {
     while(cur!=NULL)
     {
       if(cur->techm>max)
       {
           max=cur->techm;
           high=cur;
       }
        cur=cur->link;
     }
     printf("%s %s %s %d %d\n",high->name,high->cname,high->pgm,high->tm,high->techm);
    }
    return head;
}
int main() {
    struct node *head=NULL;
    struct node *newnode=NULL;
    char keyname[20];
    int n;
    scanf("%d",&n);
    if(n>=5)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);
        lowestmarks(head);
        scanf("%s",keyname);
        dname(head,keyname);
        printf("Final list is:\n");
        display_list(head);
        printf("\nSelected candidate is:\n");
         highestmarks(head);
    }
   else
       printf("Invalid input");
    return 0;
}
