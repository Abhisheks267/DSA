#include<stdio.h>
double amount(double t,char station);
int main()
{
    double t;
    double netamount,cgst,sgst,pamount;
    char station;
    scanf(" %c %lf",&station,&t);
    netamount=amount(t,station);
    printf("net amount is=%lf\n",netamount);
    return 0;
}
double amount(double t,char station)
{
    double netamount,cgst,sgst,pamount;
    switch(station)
          {
           case'I':if(t==5.0||t==14.2)
              {
               pamount=75.49*t;
               sgst=pamount*0.09;
               cgst=pamount*0.09;
               netamount=pamount+sgst+cgst;
              }

               else if(t==19)
              {
               pamount=95.50*t;
               sgst=pamount*0.12;
               cgst=pamount*0.12;
               netamount=pamount+sgst+cgst;
              }
               break;
        case'B':if(t==5||t==14.2)
              {
               pamount=77.50*t;
               sgst=pamount*0.09;
               cgst=pamount*0.09;
               netamount=pamount+sgst+cgst;
              }
               else if(t==19)
               {
               pamount=97.50*t;
               sgst=pamount*0.12;
               cgst=pamount*0.12;
               netamount=pamount+sgst+cgst;
               }
               break;
        case'H':if(t==5||t==14.2)
               {
               pamount=79.50*t;
               sgst=pamount*0.09;
               cgst=pamount*0.09;
               netamount=pamount+sgst+cgst;
               }
               else if(t==19)
               {
                pamount=99.50*t;
                sgst=pamount*0.12;
                cgst=pamount*0.12;
                netamount=pamount+sgst+cgst;
               }
               break;
    }
    return netamount;
}
