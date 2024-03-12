/*A student in Pre University College, scores marks in different subjects in mid term examination. There were
elective subjects in mid term examination which student can attend. Student has atleast 6 subjects to appear for exam.
 The student wants to check the percentage of marks he/she has scored. Also determine what is highest marks the student
scored out of appeared subjects.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 100
void read_array(int n,int marks[MAX_SIZE]);
void display_array(int n,int marks[MAX_SIZE]);
void percentage_array(int n,int marks[MAX_SIZE]);
void highest_array(int n,int marks[MAX_SIZE]);
int main() {
int n,marks[MAX_SIZE];
    scanf("%d",&n);
    if(n>=6&&n<=10)
    {
        read_array(n,marks);
        display_array(n,marks);
        percentage_array(n,marks);
        highest_array(n,marks);
    }
    else
        printf("Subjects cannot be less than 6 and more than 10.");
    return 0;
}
void read_array(int n,int marks[MAX_SIZE])
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&marks[i]);
    }
}
void display_array(int n,int marks[MAX_SIZE])
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",marks[i]);
    }
}
void percentage_array(int n,int marks[MAX_SIZE])
{
    int i,sum=0;
    float p;
    for(i=0;i<n;i++)
    {
      sum=sum+marks[i];
    }
    p=((float)sum/(n*100))*100;
    printf("\nPercentage: %0.2f",p);
}


void highest_array(int n,int votes[MAX_SIZE])
{
    int i,max=0;
    for(i=0;i<n;i++)
    {
      if(max<votes[i])
          max=votes[i];
    }
    printf("\nHighest marks: %d\n",max);
}
