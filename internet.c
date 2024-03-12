//c program to compute the additional amount to be paid by Abhilash
#include<stdio.h>
float additionalamount(char S,int plan,float ei);
int main()
{
    char S;
    int plan;
    float ei,aamount;
    printf("enter the service provider,plan,extranet used\n");
    scanf("%c %d%f",&S,&plan,&ei);
    aamount=additionalamount(S,plan,ei);
    printf("additional amount to be paid is=%f\n",aamount);
    return 0;
}
float additionalamount(char S,int plan,float ei)
{
    float aamount;
    switch(S)
    {
        case'V':if(plan==499)
                aamount=0.5*ei;
                else if(plan==599)
                aamount=0.40*ei;
                else if(plan==699)
                aamount=0.35*ei;
                break;
        case'O':if(plan==501)
                aamount=0.60*ei;
                else if(plan==601)
                aamount=0.55*ei;
                else if(plan==701)
                aamount=0.50*ei;
                break;
        case'D':if(plan==509)
                aamount=1.0*ei;
                else if(plan==609)
                aamount=0.90*ei;
                else if(plan==709)
                aamount=0.80*ei;
                break;
    }
    return aamount;
}

