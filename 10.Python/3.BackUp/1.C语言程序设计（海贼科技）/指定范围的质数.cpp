#include <stdio.h>
#include <string.h>

int n = 1000000;
int mark[1000001];

int main() {
    int c;
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;
    mark[1] = 1;
    int n,m;
    scanf("%d%d",&n,&m);   //n>m

    for (c = 2; c * c <= n; c++) 
    {
        for(int i=2;i<=n/c;i++)
        {
           // if(mark[i*c]!=1)
           // {
                mark[i*c]=1;
          //  }
        }
    }
    
    for(int i=m;i<=n;i++)
    {
        if(mark[i]==0)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}