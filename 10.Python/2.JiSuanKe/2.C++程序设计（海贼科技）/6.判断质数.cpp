#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int N,i;
    cin >> N;
    
    for( i = 2; i < N; i++ )
    {
        if(N % i == 0)
        {
            cout << "NO" << endl;
            break;
        }
    }
    if(i == N)
    {
        cout << "YES" << endl;
    }
    
    
	return 0;
}