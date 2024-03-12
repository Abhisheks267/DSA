/*There were n students absent for internal assessment 1 in a particular course. The class teacher wanted to conduct
a retake test. She asked the sudents to be seated in a class. Teacher observed that students were seated in random
order of their roll number. Then the teacher informed students to sit in reverse order. Write a modular C program
to reverse the students seating arrangement.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void read(int n,int no[100])
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&no[i]);
}
 void reverse(int n,int no[100])
 {
     int left=0,right=n-1,i;
     while(left<right)
     {
        int t=no[left];
         no[left]=no[right];
         no[right]=t;
         left++;
        right--;
     }
     for(i=0;i<n;i++)
         printf("%d ",no[i]);

 }
int main() {
int n,no[100];
    scanf("%d",&n);
    if(n>0)
    {
        read(n,no);
        reverse(n,no);
    }
    else
        printf("Absent students should be more than 0.");
    return 0;
}
