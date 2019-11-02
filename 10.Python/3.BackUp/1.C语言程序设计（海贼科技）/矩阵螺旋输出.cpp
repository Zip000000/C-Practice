#include <stdio.h>

void solve(int ans_i[],int ans_j[],int m,int n)
{
    int num_count=0;   //从count==0 开始
    int circle_count=0;
    int i=0;
    int j=0;
    int zongshu=m*n;
    while(num_count<zongshu)   //一共输入m*n组数据
    {
        for(j=circle_count; j<=n-1-circle_count;j++)
        {
            if(num_count>=zongshu)
            {
                break;
            }
            ans_i[num_count]=circle_count;
            ans_j[num_count++]=j;
        }
        for(i=circle_count+1;i<=m-1-circle_count;i++)
        {
            if(num_count>=zongshu)
            {
                break;
            }
            ans_i[num_count]=i;
            ans_j[num_count++]=j-1;
        }
        for(j=n-2-circle_count;j>=circle_count;j--)
        {
            if(num_count>=zongshu)
            {
                break;
            }
            ans_i[num_count]=i-1;
            ans_j[num_count++]=j;
        }
        for(i=m-2-circle_count;i>=circle_count+1;i--)
        {
            if(num_count>=zongshu)
            {
                break;
            }
            ans_i[num_count]=i;
            ans_j[num_count++]=j+1;
        }
        circle_count++;
    }
    
}

int main() {
    int matrix[100][100];
    int m;
    int n;
    scanf("%d %d",&m,&n);
    int zongshu=m*n;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int ans_i[zongshu];
    int ans_j[zongshu];
    solve(ans_i,ans_j,m,n);
    printf("%d",matrix[ans_i[0]][ans_j[0]]);
    for(int k=1;k<zongshu;k++)
    {
        printf(" %d",matrix[ans_i[k]][ans_j[k]]);
    }
    return 0;
}