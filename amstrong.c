#include<stdio.h>
#include<math.h>
void am(int n)
{
    int a=n,b=n,c=0,r,s=0;
    while(n!=0)
    {
        c++;
        n=n/10;
    }
    while(a!=0)
    {
       r=a%10;
       if(c==3)
       s=s+(r*r*r);
       else if(c==4)
        s=s+(r*r*r*r);
       else if(c==5)
        s=s+(r*r*r*r*r);
       else if(c>5)
         s=s+pow(r,c);
       a=a/10;
    }
    if(b==s)
        printf("amstrong");
    else
        printf("not amstrong");
}
int main()
{
    int n;
    scanf("%d",&n);
    am(n);
    return 0;
}
