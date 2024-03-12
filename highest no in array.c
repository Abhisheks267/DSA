//highest in a array
#include<stdio.h>
#define MAX_SIZE 100
void read_array(int elements[MAX_SIZE],int N);
void display_array(int elements[MAX_SIZE],int N);
int highest_array(int elements[MAX_SIZE],int N);
int main()
{
    int N,elements[MAX_SIZE],max;
    scanf("%d",&N);
    if(N>0)
    {
      read_array(elements,N);
      display_array(elements,N);
      max=highest_array(elements,N);
        printf("\nHighest number in array is %d.",max);
    }
    else
        printf("Array cannot be less than 0.");
     return 0;
}
void read_array(int elements[MAX_SIZE],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        scanf("%d",&elements[i]);
    }
}
void display_array(int elements[MAX_SIZE],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d\t",elements[i]);
    }
}
int highest_array(int elements[MAX_SIZE],int N)
{int i,max=0;
for(i=0;i<N;i++)
{
    if(max<elements[i])
    max=elements[i];
}
 return max;
}
