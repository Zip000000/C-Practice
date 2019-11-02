#include <stdio.h>
int main() {
	int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("%d",i);
        for(int j=2;j<=n-i+1;j++)
        {
            printf(" %d",i);
        }
        printf("\n");
    }

    return 0;
}