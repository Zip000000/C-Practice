#include <stdio.h>
int main() {
    int max;
    int a[1001];
    a[0]=1;a[1]=1;a[2]=0;
    scanf("%d",&max);
    for(int i=3;i<=max;i++)
    {
        a[i]=0;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                a[i]=1;
            }
        }
    }
    for(int i=0;i<=max;i++)
    {
        if(a[i]==0)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}