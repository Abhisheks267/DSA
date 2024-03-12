/*Indian Cricket team is doing so well in all 3 formats: (1) 20-20 2) ODI 3) TEST) -of the game. They are number 1
in all formats. Rohit Sharma and Rahul Dravid are leading the team well.
Consider currently Indian squad has N players and read the runs scored by each of them in 20-20, ODI and TEST matches
respectively. Display the total runs scored by each player and find the player with highest total runs scorer.
for more than 5 players.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void read_2darray(int m,int no[100][3])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
            scanf("%d",&no[i][j]);
    }

     for(i=0;i<m;i++)
     {
        for(j=0;j<3;j++)
            printf("%d ",no[i][j]);
         printf("\n");
     }
}
void countarray(int m,int no[100][3])
{
    int i,j,sumr[100]={0},max=0,p;

    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        {
              sumr[i]=sumr[i]+no[i][j];
        }
    }
   printf("\n");
   for(i=0;i<m;i++)
     {
        printf("Player %d: %d ",i+1,sumr[i]);
        printf("\n");
     }
   for(i=0;i<m;i++)
   {
       if(max<sumr[i])
       {
           max=sumr[i];
           p=i+1;
       }
   }
    printf("\nPlayer %d has highest total runs scored of %d",p,max);

}


int main() {
int m,n,no[100][3];
    scanf("%d%d",&m,&n);
    if(m>5&&n==3)
    {
      read_2darray( m,no);
      countarray(m,no);
    }
    else
        printf("Invalid players or game formats");
    return 0;
}
