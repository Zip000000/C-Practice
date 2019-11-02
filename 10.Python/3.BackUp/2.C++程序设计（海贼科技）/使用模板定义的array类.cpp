#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

template<typename T>
class Array
{
public:
    Array(int n)
    {
        p=new T[n];
        count=0;
        count_n=n;
    } 
    
    void insert(T c)  
    {
        if(count<count_n)
        {
            p[count]=c;
            count=count+1;
        }
        else
        {
            cout<<"array full"<<endl;
        }
    }
    
    void showAll()
    {
        for(int i=0;i<count;i++)
        {
            cout<<p[i]<<endl;
        }
    }
    
    
private:
    int count_n;
    int count=0;
    T* p;    
};
 
int main() {
    string str1="yangzhou301";
    Array<char> arr1(str1.length());
    for(auto c:str1)
    {
        arr1.insert(c);
    }
    arr1.showAll();
    int num[]={1,9,2,6,0,8,1,7};
    Array<int>arr2(sizeof(num)/sizeof(int));
    for(auto c:num)
    {
        arr2.insert(c);
    }
	arr2.showAll();
    arr2.insert(301);
    return 0;
}
