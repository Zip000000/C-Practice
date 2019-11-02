#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = n-i; j>0; j--)
        {
            if(j==n-i)
            {
                cout<<j;
            }
            else
            {
                cout<<" "<<j;
            }
        }
        cout<<endl;
    }
    
    
    


    return 0;
}