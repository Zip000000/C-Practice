#include <stdio.h>

int main() {
    int matrix_a[10][10];
    int matrix_b[10][10];
    int m;
    int n;
    int ans[10][10];
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix_a[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&matrix_b[i][j]);
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            ans[i][j]=0;
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int k=0;k<m;k++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][k]+=matrix_a[i][j]*matrix_b[j][k];
            }
            printf("%d",ans[i][k]);
            if(k!=m-1) printf(" ");
        }
        printf("\n");
    }
	

    return 0;
}