/*You are in charge of the cake for your brother's birthday and have decided the cake will have one candle for each year
 of his total age. When he blows out the candles, he’ll only be able to blow out the tallest ones. Your task is to find
 out how many candles he can successfully blow out.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100
void read_array(int n,int height[MAX_SIZE]);
void display_array(int n,int height[MAX_SIZE]);
int tallest_candle(int n,int height[MAX_SIZE]);
void candles_blown(int n,int height[MAX_SIZE],int max);
int main()
{
    int n,height[MAX_SIZE],max;
    scanf("%d",&n);
    if(n>0)
    {
        read_array(n,height);
        display_array(n,height);
        max=tallest_candle(n,height);
        printf("\nTallest Candle = %d",max);
        candles_blown(n,height,max);
    }
    else
        printf("Invalid input.");
    return 0;
}
void read_array(int n,int height[MAX_SIZE])
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&height[i]);
    }
}
void display_array(int n,int height[MAX_SIZE])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",height[i]);
    }
}
int tallest_candle(int n,int height[MAX_SIZE])
{
    int i,max=0;
    for(i=0;i<n;i++)
    {
      if(max<height[i])
          max=height[i];
    }
    return max;
}
void candles_blown(int n,int height[MAX_SIZE],int max)
{
  int i,c=0;
  for(i=0;i<n;i++)
  {
      if(height[i]==max)
          c++;
  }
    printf("\nTallest Candles blown = %d",c);
}
