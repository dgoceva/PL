#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double cf_converter(double cel)
{
    return cel * (float)9 / 5 + 32;
}

int main()
{
    double start;
    double end;
    float step;
    double cel;
    double temp;

    printf("Input start: ");
    scanf("%lf", &start);
    printf("Input end: ");
    scanf("%lf", &end);
    printf("Input step: ");
    scanf("%f", &step);

    if (end < start && step > 0)
    {
        puts("start should be less than end, or step should be negative");
        return -1;
    }

    puts("Results:");
    puts("Cel\t\tFar");
    puts("-----------------------------------");
	if (step < 0){
	    temp = (end > start) ? end : start;
	    end = (end < start) ? end : start;
	    start = temp;
    // i+=step => i=i+step
	    for (cel = start; cel >= end; cel += step)
	    {
	        printf("%g\t\t%g\n", cel, cf_converter(cel));
	    }
	} else {
	    temp = (end < start) ? end : start;
	    end = (end > start) ? end : start;
	    start = temp;
    // i+=step => i=i+step
	    for (cel = start; cel <= end; cel += step)
	    {
	        printf("%g\t\t%g\n", cel, cf_converter(cel));
	    }
	}


    return 0;
}
