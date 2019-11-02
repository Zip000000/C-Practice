#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n = 1000000;
int mark[1000001];

int main() {
    int c;
    memset(mark, 0, sizeof(mark));  //初始化为0
    mark[0] = 1;
    mark[1] = 1;
    
    int N,M;
    cin>>N>>M;    //N>M
    

    for (c = 2; c * c <= N; c++) 
    {
        for(int j=2;j*c<=N;j++)
        {
            if(mark[j*c]!=1)
            {
                mark[j*c]=1;
            }
        }
  	}
    for(int k=M;k<=N;k++)
    {
        if(mark[k]!=1)
        {
            cout<<k<<endl;
        }
    }

    return 0;
}