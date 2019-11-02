#include <stdio.h>
#include <math.h>
int main() {
    double d,h,l;
    scanf("%lf%lf",&d,&h);
    l=sqrt(d*d+h*h);
    printf("%.2f\n%.2f",d+h+l,d*h/2);


    return 0;
}