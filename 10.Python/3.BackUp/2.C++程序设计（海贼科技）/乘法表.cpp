#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int n,i,j;
     cin >> n;
    for( i = 1; i <= n; i++)
    {
        for( j = i; j < n; j++)
        {
            cout<<i<<"*"<<j<<"="<<i*j<<"	";
        }
        cout<<i<<"*"<<j<<"="<<i*j<<endl;
    }
    
    
    


    return 0;
}