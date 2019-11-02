#include <stdio.h>
#include <string.h>
int main() {
    int arr[32];
    char input[500];
    char input_linshi;
    int input_count=0;
    memset(arr,0,sizeof(arr));
    while(scanf("%c", &input_linshi) != EOF)
    {
        if(input_linshi=='\n')
        {
            break;
        }
        else
        {
            input[input_count]=input_linshi;
            input_count++;
        }
    }
    int k=input_count;
    // for(int i=0;i<input_count;i++)
    // {
    //     printf("%c",input[i]);
    // }
    // printf("\n*************");
    // for(int i=0;i<input_count;i++)
    // {
    //     printf("%d",(int)input[i]);
    // }
    // printf("\n");
  
    for(int i=1;i<=k;i++)
    {
        arr[i%32]+=(int)input[i-1];
    }
    // for(int j=0;j<32;j++)
    // {
    //     printf("%d",arr[j]);
    // }
    // printf("\n");
    int bits[32];
    for(int j=0;j<32;j++)
    {
        bits[j]=arr[31-j]^(arr[j]<<1);
    }
    // for(int j=0;j<32;j++)
    // {
    //     printf("%d",bits[j]);
    // }
    // printf("\n");
    for(int j=0;j<32;j++)
    {
        printf("%c",(char)(bits[j]%85+34));
    }
    
    return 0;
}