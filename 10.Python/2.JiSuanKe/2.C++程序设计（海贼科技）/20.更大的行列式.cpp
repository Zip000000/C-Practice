#include <iostream>
using namespace std;

int main() {
    int a[3][3];
    int b[2][2];
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>b[i][j];
        }
    }
    
    int a_ans=0,b_ans=0;
    
    a_ans=a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]
        -a[0][2]*a[1][1]*a[2][0]-a[0][0]*a[1][2]*a[2][1]-a[0][1]*a[1][0]*a[2][2];
    
    b_ans=b[0][0]*b[1][1]-b[0][1]*b[1][0];
    
    int ans=a_ans>b_ans?a_ans:b_ans;
    cout<<ans;
    
    

    return 0;
}