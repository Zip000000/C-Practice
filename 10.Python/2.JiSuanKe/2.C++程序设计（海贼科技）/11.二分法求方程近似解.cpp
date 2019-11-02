#include <cstdio>
#include <cmath>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double x_mid , x_left = -20 , x_right = 20;
    double f_value;
    double abs_f_value=100;
    //不让用 abs 啊啊啊啊啊啊啊啊啊啊 啊啊 
    while(abs_f_value > EPSILON)
    {
        x_mid=(x_left + x_right)/2;
        f_value=(*f)(p,q,x_mid);
        //printf("(*f)(p,q,x_mid)=%f/n",(*f)(p,q,x_mid));
        
        if(f_value>0)
        {
            if((*f)(p,q,x_left) < 0)
            {
                x_right = x_mid;
            }
            else
            {
                x_left = x_mid;
            }
        }
        else //*******
        {
			if((*f)(p,q,x_left) < 0)
            {
                x_left = x_mid;
            }
            else
            {
                x_right = x_mid;
            }         
        }
        
        if(f_value>0)
        {
            abs_f_value = f_value;
        }
        else
        {
            abs_f_value = -f_value;
        }
    }
    return x_mid;
}

double f(int p, int q, double x) {
    return p * x + q;
}