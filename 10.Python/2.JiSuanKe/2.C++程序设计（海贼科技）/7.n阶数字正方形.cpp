#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int n;
    cin >> n;
    
    for( int i = 0; i < n; i++)
    {
        for( int j = 0;j < n; j++)
        {
            if(j == 0)
            {
                cout << i+1;
            }
            else
            {
            cout<<" "<< i+1;  
            }

        }
        cout<<endl;
    }


    return 0;
}