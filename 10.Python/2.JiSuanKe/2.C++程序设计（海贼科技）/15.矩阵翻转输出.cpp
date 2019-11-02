#include <iostream>
using namespace std;

int main() {
    int matrix[100][100];
    int m;
    int n;
	cin>>m>>n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    int judge=0;    
	cin>>judge;
    if(judge==0)   //shuzhi
    {
        
        for(int i=m-1; i>=0;i--)
        {
            cout<<matrix[i][0];
            for(int j=1; j<n; j++)
            {
                cout<<" "<<matrix[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
        
        for(int i=0; i<m; i++)
        {
            cout<<matrix[i][n-1];
            for(int j=n-2; j>=0; j--)
            {
                cout<<" "<<matrix[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}



