#include <cstdio>
#include <iostream>
using namespace std;

int BinarySearch(int numbers[],int left,int right,int key)
{
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(numbers[mid]>key)
        {
            right=mid-1;
        }
        else if(numbers[mid]<key)
        {
            left=mid+1;
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
    while (scanf("%d %d", &n, &k) != EOF) 
    {
		int ans[k];
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &numbers[i]);
        }
        for (j = 0; j < k; j++) 
        {
            scanf("%d",&m);
			ans[j]=BinarySearch(numbers,0,n,m);
        }
        printf("%d",ans[0]+1);
          for(j=1;j<k;j++)
        {
            printf(" %d",ans[j]+1);
        }
    }
    return 0;
}