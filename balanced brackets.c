/*Write a modular C program to check an infix expression has balanced brackets. Balanced brackets represents that an infix expression should have an appropriate opening and closing bracket.

An open '(' bracket should have an appropriate close ')' in its place.

Similarly, an open '{' bracket should have an appropriate close '}' in its place.

Also an open '[' bracket should have an appropriate close ']' in its place.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 50
struct stack
{
    char ex[SIZE];
    int top;
};

void push(struct stack *sptr,char expr)
{
    if(sptr->top==SIZE-1)
        printf("Stack overflow.\n");
    else
    {
        sptr->top++;
        sptr->ex[sptr->top]=expr;
    }
}

char pop(struct stack *sptr)
{
    char ch;
    if(sptr->top==-1)
        return -1;
    else
    {
      ch=sptr->ex[sptr->top];
      sptr->top--;
      return ch;
    }
}
int brackets(struct stack *sptr,char expr[50])
{
    int i=0;
    char ch;
    while(expr[i]!='\0')
    {
        if(expr[i]=='('||expr[i]=='{'||expr[i]=='[')
        {
            push(sptr,expr[i]);
        }
        else if(expr[i]==')')
        {
            if(sptr->top==-1)
                return 0;
            else
            {
                ch=pop(sptr);
                if(ch!='(')
               return 0;
            }
        }
        else if(expr[i]=='}')
        {
            if(sptr->top==-1)
                return 0;
            else
            {
                ch=pop(sptr);
                if(ch!='{')
               return 0;
            }
        }
        else if(expr[i]==']')
        {
            if(sptr->top==-1)
                return 0;
            else
            {
                ch=pop(sptr);
                if(ch!='[')
               return 0;
            }
        }
      i++;
    }
    if(sptr->top==-1)
        return 1;
    else
        return 0;
}
int main() {
struct stack s,*sptr;
    sptr=&s;
    sptr->top=-1;
    char e[SIZE];
    scanf("%s",e);
    int v=brackets(sptr,e);
    if(v==1)
        printf("Valid expression.");
    else
        printf("Invalid expression.");

    return 0;
}
