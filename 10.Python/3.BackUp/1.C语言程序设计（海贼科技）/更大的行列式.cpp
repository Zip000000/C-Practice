#include <stdio.h>
void input(int num,int matrix[num][num])
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
}
int solve(int num,int arr[num][num])
{
    int ans=0;
    int sum_zheng=0;
    int sum_fu=0;
    int add=1;
    int count=0;
    if(num==2)
    {
        return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
    }
	while(count<num)   //0 1 2
    {
        for(int i=0;i<num;i++)
        {
            add=add*arr[(0+i)%num][(count+i)%num];
        }
        sum_zheng+=add;
        add=1;
        count++;
    }
    count--;
	while(count>=0)   //2 1 0
    {
        for(int i=0;i<num;i++)
        {
            add*=arr[(0+i)%3][(count+3-i)%3];
        }
        sum_fu+=add;
        add=1;
        count--;
    }
    ans=sum_zheng-sum_fu;
    return ans;
}

int main() {
    int a[3][3];
    int b[2][2];
    int ans_a=0;
    int ans_b=0;
    input(3,a);
    input(2,b);
    ans_a=solve(3,a);
    ans_b=solve(2,b);
	printf("%d",ans_a>ans_b?ans_a:ans_b);    
    return 0;
}