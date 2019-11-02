#include <stdio.h>

int main() {
    int matrix[3][3];
    int i;
    int j;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    
    for(int i=0;i<3;i++)
    {
        printf("%d",matrix[2][i]);
        for(int j=1;j>=0;j--)
        {
            printf(" %d",matrix[j][i]);
        }
        printf("\n");
    }
    
    
    
    return 0;
}