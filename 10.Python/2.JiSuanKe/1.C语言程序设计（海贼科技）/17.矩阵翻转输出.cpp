#include <stdio.h>
int main() {
    int matrix[100][100];
    int m;
    int n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int judge;
    scanf("%d",&judge);   //1水平 0竖直
    
	if(judge==1)
    {
        //printf("judge=1\n")
        for(int i=0;i<m;i++)
        {
            for(int j=n-1;j>0;j--)
            {
                printf("%d ",matrix[i][j]);
            }
            printf("%d\n",matrix[i][0]);
        }        
    }
    else
    {
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<n-1;j++)
            {
                printf("%d ",matrix[i][j]);
            }
            printf("%d\n",matrix[i][n-1]);
        }
    }
    return 0;
}