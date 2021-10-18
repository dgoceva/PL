#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define EPS 1e-8

double pi()
{
    double sum=1;
    double prevMember;
    double currMember=1;
    int number=3;
    int sign=-1;

    do
    {
        prevMember=currMember;
        currMember=(double)sign/number;
        sum += currMember;
        number += 2;
        sign *= -1;
    } while(fabs(currMember-prevMember)>=EPS);

    return sum*4;
}

double pi_members()
{
    double sum=1;
    int number=3;
    int sign=-1;
    int i;

    for(i=0;i<10000;i++)
    {
        sum += (double)sign/number;
        number += 2;
        sign *= -1;
    }
    return sum*4;
}
int main()
{
    clock_t start,end;
    start=clock();
    printf("original Pi: %.10f\tcalculate Pi: %.10f\n",M_PI,pi());
    end=clock();
    printf("Time: %g\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
