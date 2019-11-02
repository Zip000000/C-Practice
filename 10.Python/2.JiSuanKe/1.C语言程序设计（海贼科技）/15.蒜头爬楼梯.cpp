#include <stdio.h>

int step(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==-1)
    {
        return 0;
    }
    else if(n==1)
    {
        return 0;
    }
    else
    {
        return (step(n-2)+step(n-3));
    }
}

int main() {
	int n;
    scanf("%d",&n);
    int ans=step(n);
    printf("%d",ans);
    return 0;
}