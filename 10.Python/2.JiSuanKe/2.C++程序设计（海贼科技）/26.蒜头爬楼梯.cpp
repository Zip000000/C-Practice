
#include<iostream>

using namespace std;

int step(int n)
{
	if(n==0)
	{
		return 1;
	}
	else if(n==-1)
	{
		return 0;
	}
	else if(n==1)
	{
		return 0;
	}
	else
	{
		return (step(n-2)+step(n-3));
	}
}

int main()
{
	int n;
	cin>>n;
	cout<<step(n);
    
    return 0;
}