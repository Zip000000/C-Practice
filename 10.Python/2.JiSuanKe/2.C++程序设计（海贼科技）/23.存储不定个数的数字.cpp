#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
    bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    int input;
    vector <int> num;
    
    while(cin>>input)
    {
        auto temp=find(num.begin(),num.end(),input);
        if(temp==num.end())
        {
        num.push_back(input);    
        }
    }

    sort(num.begin(),num.end(),compare);
    
    int i=0;
    for(i=0;i<num.size();i++)
    {
        cout<<num[i]<<endl;
    }
    //vector<int>::iterator t=num.end();
    cout<<i;
    
    
    return 0;
}