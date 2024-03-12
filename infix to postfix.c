/*Write a modular C program to convert a infix expression to an postfix expression. Infix expression can be with brackets or without brackets.

Example 1: Infix expression is (a+b). Its equivalent postfix expression is ab+.

Example 2: Infix expression is a+b-c. Its equivalent postfix expression is ab+c-.*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 20
struct stack
{
  char data[SIZE];
  int top;
};
void push(struct stack *sptr,char ch)
{
    if(sptr->top==SIZE-1)
        printf("Stack overflow.\n");
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=ch;
    }
}

char pop(struct stack *sptr)
{  char ch='\0' ;
    if(sptr->top==-1)
        return ch;
    else
    {
        ch=sptr->data[sptr->top];
        sptr->top--;
         return ch;
    }
}
char peek(struct stack *sptr)
{   char ch='\0';
    if(sptr->top==-1)
        return ch;
    else
      ch=sptr->data[sptr->top];
    return ch;
}
int precedence(char ch)
{
    switch(ch)
    {
        case '#':return 0;
                 break;
        case '(':return 1;
                 break;
        case '+':
        case '-':return 2;
                 break;
        case '*':
        case '/':
        case '%':return 3;
                 break;
        case '^':return 4;
                 break;
    }

    return;
}
void postfixconversion(struct stack *sptr,char infix[SIZE])
{
    char postfix[SIZE],ch,temp;
    int i=0,j=0;
    push(sptr,'#');
    while((infix[i])!='\0')
    {   ch=infix[i];
        if(ch =='(')
            push(sptr,ch);
        else if(isalnum(ch))
            postfix[j++]=ch;
        else if(ch==')')
        {
            while(sptr->data[sptr->top]!='(')
                 postfix[j++]=pop(sptr);
            temp=pop(sptr);
        }
        else
        {
            while(precedence(peek(sptr))>=precedence(ch))
                   postfix[j++]=pop(sptr);
            push(sptr,ch);
        }
        i++;
    }
        while(sptr->data[sptr->top]!= '#')
               postfix[j++]=pop(sptr);
              postfix[j]='\0';
    printf("Given Infix Expression: %s\n",infix);
    printf("Postfix Expression: %s\n",postfix);
}
int main() {
   struct stack st, *sptr;
   sptr=&st;
   sptr->top=-1;
   char infix[SIZE];
   scanf(" %s",infix);
   postfixconversion(sptr,infix);

    return 0;
}
