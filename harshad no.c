/*In mathematics, a Harshad number in a given number base is an
integer divisible by the sum of its digits when written in that base.
Harshad numbers in base n are also known as n-harshad  numbers.
Sham is given with number, where he has to find out whether the number is
Harshad number. If it's Harshad Number print sum of its digits else print sum of odd digits sum. Please help sham to solve the problem by using Problem Solving Framework and Write the modular C program.

Ex1: Input: 152

Output: 8

1+5+2=8 152 is divisible by 8, sum i.e 1+5+2=8
*/
#include <stdio.h>
#include <math.h>

void harshad(int n)
{
    int rem=0,sum=0,sumo=0;
    int num=n;
    while(n!=0)
    {
        rem=n%10;
        sum=sum+rem;
        if(rem%2!=0)
        {
            sumo=sumo+rem;
        }
        n=n/10;
    }
    if(num%sum==0)
        {printf("%d\n",sum);
         printf("%d is a harshad no\n",num);
        }
    else
       printf("%d",sumo);
}
int main() {
int n;
printf("enter a more than a one digit no\n");
    scanf("%d",&n);
    if(n>=10)
        harshad(n);
    return 0;
}
