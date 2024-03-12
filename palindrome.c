/*There are odd number of kids running in a circular sports ground. Every kid holds a board with a integer number printed
 on it. Physical Education (PE) director wants to know whether the numbers are same in forward direction and reverse
 direction. If the numbers same in both the directions, PE director says them as palindrome. Otherwise non palindrome.*/
 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
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
        scanf(" %d",&newnode->data);
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
void display(struct node *head)
{  struct node *start=NULL,*end=NULL;
   start=head;
   end=head->llink;
    int st=0;
 while(start!=end)
 {
     if(start->data!=end->data)
     {
         st=1;
         break;
     }
     start=start->rlink;
     end=end->llink;
 }
 if(st==1)
 {
     printf("non palindrome");
 }
 else
    printf("palindrome");

}
int main() {
struct node *head=NULL;
int n;
scanf("%d",&n);
if(n%2!=0)
{
    for(int i=0;i<n;i++)
    head=insertendcdll(head);
    display(head);
}
else
printf("Invalid input");

    return 0;
}
