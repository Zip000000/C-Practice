#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int m;
    int numbers[10];
    int i;

    // 读入给定的数字
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for(i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(numbers[j]<numbers[j+1])
            {
                int temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }
        }
    }
    cout<<numbers[0];
    for(i=1;i<n;i++)
    {
        cout<<" "<<numbers[i];
    }
    
    return 0;
}