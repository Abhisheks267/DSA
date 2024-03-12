#include<stdio.h>
int main()
{
    float fine;
    int days;
    char type;
    printf("enter C for central library, M for main library and days for late return \n");
    scanf("%c%d",&type,&days);
    if(days<=0)
        printf("book returned in time\n");
    else if(type=='C')
    {
        if(days>0 && days<=5)
        {
            fine=0.5*days;
            printf("fine is %f \n",fine);
        }
        else if(days>=6 && days<=10)
        {
            fine=(0.5*5)+(1*(days-5));
            printf("fine is %f \n",fine);
        }
        else if(days>=11 && days<=15)
        {
            fine=(0.5*5)+(1*(5))+(5*(days-10));
            printf("fine is %f \n",fine);
        }
        else if(days>15)
            printf("ur membership cancelled \n");


    }
    else if(type=='M')
    {
        if(days>=0 && days<=5)
        {
            fine=1*days;
            printf("fine is %f \n",fine);
        }
        else if(days>=6 && days<=10)
        {
            fine=(1*5)+(2*(days-5));
            printf("fine is %f \n",fine);
        }
        else if(days>=11 && days<=15)
        {
            fine=(1*5)+(2*(5))+(10*(days-10));
            printf("fine is %f \n",fine);
        }
        else if(days>15)
            printf("U cannot barrow book anymore \n");
    }
    else
        printf("invalid library type\n");
    return 0;

}
