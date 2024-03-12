/*Simulate the forward and back button of the web browser using DLL. The buttons should perform the following operations:
a) The forward button should move the webpage to next webpage.
b) The back button should move the webpage to previous webpage.
c) At any point, after moving certain webpages forward or back, web browser should be able to display current webpage information.
d) The web browser should display one webpage information at a time.
Input Format
First line is N - number of webpages visited in the web browser.
Second line onwards is webpage details (website name, copyright, year of last update)
Last but one line is movement of webpages K times in forward direction from first webpage.
Last line is movement of webpages from current webpage back L times.

Constraints
N is positive.
K, L < N */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
  char web[25],brwoser[20];
  int year;
  struct node *llink,*rlink;
};
struct node* create()
{
    struct node *newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory empty.");
    else
    {
        scanf("%s%s%d",newnode->web,newnode->brwoser,&newnode->year);
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
void display(struct node *head,int k,int l)
{
    struct node *cur=head;
    printf("%s %s %d\n",head->web,head->brwoser,head->year);
    for(int i=0;i<k;i++)
    {
        cur=cur->rlink;
    }
    printf("\n%s %s %d\n",cur->web,cur->brwoser,cur->year);
    for(int i=0;i<l;i++)
    {
        cur=cur->llink;
    }
    printf("\n%s %s %d\n",cur->web,cur->brwoser,cur->year);

}
int main() {
struct node *head=NULL;
int n,k,l;
    scanf("%d",&n);
    if(n>0)
    {
       for(int i=0;i<n;i++)
           head=insertendcdll(head);
        scanf("%d%d",&k,&l);
        display(head,k,l);
    }

    return 0;
}
