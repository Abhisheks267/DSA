/* Zanfi Systems is a software development Multi National Company. It has offices in different countries.
 Due to Lockdownand slow work progress, company had deducted 30% salary for all the employees. Consider there are
 N employees in M offices, based on actual salary, the lockdown salary of each employee after deduction is computed by
 the Human Resource Manager is.
 */
 #include <stdio.h>
#include <math.h>
#include <stdlib.h>
void read_2darray(int m,int n,int salary[100][100])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&salary[i][j]);
    }
}
void displaysalary(int m,int n,int salary[100][100])
{
    int i,j,dsalary[100][100]={0};
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
         dsalary[i][j]=salary[i][j]-(salary[i][j]*0.3);
        }
    }
    printf("Salary after deduction:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",dsalary[i][j]);
        printf("\n");
    }
}


int main() {
int m,n,salary[100][100];
    scanf("%d%d",&m,&n);
    if(m>0&&n>0)
    {
     read_2darray( m, n, salary);
     displaysalary( m, n, salary);
    }
    else
        printf("Rows and columns should be more than 0.");
    return 0;
}
