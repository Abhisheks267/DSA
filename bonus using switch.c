//C program to compute bonus using switch
#include<stdio.h>
float bonusgiven(char gender,float salary)
{  float bonus;
     switch(gender)
    {
     case 'M':if(salary<10000)
                bonus=0.07*salary;
              else
                bonus=0.05*salary;
              break;
    case 'F':if(salary<10000)
                bonus=0.12*salary;
             else
                 bonus=0.10*salary;
             break;
    default:printf("invalid input for gender \n");
             break;
    }
    return bonus;
}
int main()
{
    char gender;
    float salary,bonus;
    printf("enter gender and salary \n");
    scanf("%c%f",&gender,&salary);
    bonus=bonusgiven(gender,salary);
    printf("The bonus to be given is:%0.2f",bonus);
             return 0;
}
