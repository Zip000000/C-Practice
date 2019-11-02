#include <iostream>
using namespace std;

int main() {
    int matrix_a[10][10];
    int matrix_b[10][10];
    int m;
    int n;
    int ans[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            ans[i][j]=0;
            matrix_a[i][j]=0;
            matrix_b[i][j]=0;
        }
    }
    cin>>m>>n;
    int min=m>n?n:m;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix_a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix_b[i][j];
        }
    }
    
    
	for(int i=0;i<m;i++)
    {
        
        for(int k=0;k<m;k++)
        {
            
            for(int j=0;j<n;j++)
            {
            ans[i][k]+=matrix_a[i][j]*matrix_b[j][k];
            //ans[i][k+1]=matrix_a[i][j]*matrix_b[j][i+1];
            }
        }
    }
    
    for(int i=0;i<m;i++)
    {
        cout<<ans[i][0];
        for(int j=1;j<m;j++)
        {
            cout<<" "<<ans[i][j];
        }
        cout<<endl;
    }
    

    return 0;
}

