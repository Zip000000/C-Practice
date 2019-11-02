#include <stdio.h>


int Search_Bin(int numbers[],int begin,int end,int key)
{
    int mid;
    while(begin<=end)
    {
        mid=(begin+end)/2;
        if(numbers[mid]>key)
        {
            end=mid-1;
        }
        else if(numbers[mid]<key)
        {
            begin=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
    
}
int main() {
    int n;
    int k;
    int numbers[1000001];
    int m;
    int i;
    int j;

    // 反复读入数字和查找数字的数量
    while (scanf("%d %d", &n, &k) != EOF) 
    {
        int ans[k];
        // 读入给定的数字
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &numbers[i]);
        }

        for (j = 0; j < k; j++) 
        {
            // 读入待查找的数字，
            scanf("%d", &m);
            // 请在下面完成查找读入数字的功能
            ans[j]=Search_Bin(numbers,0,n,m);
        }
        printf("%d",ans[0]+1);
        for(int temp=1;temp<k;temp++)
        {
            printf(" %d",ans[temp]+1);
        }
    }
    return 0;
}