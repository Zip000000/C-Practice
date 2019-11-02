#include <iostream>
#include <cmath>

using namespace std;

void hanno(int n, char a, char b, char c)
{
    if(n==1)
    {
        cout << a << "-->" << c << endl;
    }
    else
    {
        hanno(n-1,a,c,b);
        cout<< a << "-->" << c << endl;
		hanno(n-1,b,a,c);
    }
    
}

int main()
{
    int n;
    cin >> n;
    char a='A', b='B', c='C';  //A 起始的 B 中转  C 最终的
    
    hanno(n,a,b,c);
    
    
    
    
    return 0;
}