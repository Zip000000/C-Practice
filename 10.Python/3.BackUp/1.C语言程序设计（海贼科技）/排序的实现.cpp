#include <stdio.h>

int main() {
    int n = 10;
    int m;
    int numbers[10];
    int i;

    // 读入给定的数字
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
	for(int p=0;p<n-1;p++)
    {
        for(int q=p+1;q<n;q++)
        {
            if(numbers[p]<numbers[q])
            {
                int temp=numbers[q];
                numbers[q]=numbers[p];
                numbers[p]=temp;
            }
        }
    }
    printf("%d",numbers[0]);
    for(int k=1;k<n;k++)
    {
        printf(" %d",numbers[k]);
    }
        

    return 0;
}