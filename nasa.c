/*Harvard University US, Professor of School of Mechanical Engineering conducted the screening on Atmospheric Science to
 check the ability of students capable to work on Young Scientists, NASA projects. The screening was held in room no
 C101. After the screening was over, it was time to announce the list and their scores.The Professor displays the
 students who has scored an S grade in screening. (S grades are those students who scored above 90 marks).
 */
 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[20],school[20];
    int marks;
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
        scanf("%s%s%d",newnode->name,newnode->school,&newnode->marks);
        newnode->link=NULL;
    }
    return newnode;
}
struct node* insertend(struct node *head)
{
   struct node *newnode=NULL,*cur=NULL;
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
struct node*  sgrade(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
      printf("List empty");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            if(cur->marks>90)
                printf("%s %s %d\n",cur->name,cur->school,cur->marks);
            cur=cur->link;
        }
    }
    return head;
}
struct node* delete(struct node *head)
{
     struct node *cur=head,*z=NULL,*prev=NULL,*prevz=NULL;
    if(head==NULL)
        printf("List empty\n");
    else
    {
     while(cur!=NULL)
     {
       if(cur->marks==0)
       {
          printf("%s %s %d\n",cur->name,cur->school,cur->marks);
           prevz=prev;
           z=cur;
           break;
       }
        prev=cur;
        cur=cur->link;
     }
        if(head==z)
      {
        head=head->link;
        free(z);
      }
     else
     {
        prevz->link=z->link;
         free(z);
     }

    }
    return head;
}
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("list empty");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%s %s %d\n",cur->name,cur->school,cur->marks);
            cur=cur->link;
        }
    }
}
int main() {
    struct node *head=NULL;
    int n;
    scanf("%d",&n);
    if(n>0)
    {   for(int i=0;i<n;i++)
        head=insertend(head);
        printf("S grade list is:\n");
        sgrade(head);
        printf("\nStudent with 0 marks:\n");
        delete(head);
        printf("\nUpdated list is:\n");
        display(head);
    }
    else
        printf("Invalid input");
    return 0;
}
