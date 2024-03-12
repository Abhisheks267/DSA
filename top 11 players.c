/*CAPTAIN OF INDIAN CRICKET TEAM WANTS TO SELECT TOP 11 OUT OF 20 PLAYERS.

CAPTAIN WANTS TO LIST PLAYERS ACCORDING TO HIGHEST TO LOWEST BATTING AVERAGE OBTAINED IN THE PREVIOUS CRICKET MATCHES.

HELP THE CAPTAIN TO SELECT THE TOP 11 HIGHEST BATTING AVERAGE SCORED PLAYERS.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100
void read_array(int n,float avg[MAX_SIZE]);
void top_11(int n,float avg[MAX_SIZE]);
int main() {int n;
            float avg[MAX_SIZE];
            printf("enter no of players\n");
            scanf("%d",&n);
            if(n>=11)
            {
                read_array(n,avg);
                top_11(n,avg);
            }
            else
                printf("Number of players should be atleast 11.");
            return 0;
}
void read_array(int n,float avg[MAX_SIZE])
{
    int i;
    printf("enter avg");
   for(i=0;i<n;i++)
   {
     scanf("%f",&avg[i]);
   }
}
void top_11(int n,float avg[MAX_SIZE])
{
    int i,j;
    float temp=0;
    printf("Top 11 batting average players:\n");
    for(i=0;i<n;i++)
    {
     for(j=i+1;j<n;j++)
         if(avg[i]<avg[j])
         {
             temp=avg[i];
             avg[i]=avg[j];
             avg[j]=temp;
         }
    }
    for(i=0;i<11;i++)
    {
        printf("%0.2f ",avg[i]);
    }
}
