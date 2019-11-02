#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];
    int i;
    int j;
	
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>matrix[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        cout<<matrix[2][i];
        for(j=1;j>=0;j--)
        {
            cout<<" "<<matrix[j][i];
        }
        cout<<endl;
    }
    
    return 0;
}