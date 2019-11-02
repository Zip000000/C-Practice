#include <iostream>
#include <cctype>
using namespace std;
void upper_case_count(char arr[31]) {
    // 请在下面实现统计并输出大写字母个数的功能
	int sum=0;
    for(int i=0;i<31;i++)
    {
        int judge=isupper(arr[i]);
       if(judge==1)
       {
           sum+=1;         
       }

    }
       cout<<sum<<endl; 
}
void lower_case_count(char arr[31]) {
    // 请在下面实现统计并输出小写字母个数的功能
	int sum=0;
    for(int i=0;i<31;i++)
    {
        if(islower(arr[i]))
            sum+=1;
    }
    cout<<sum<<endl;
    
}
void digit_count(char arr[31]) {
    // 请在下面实现统计并输出数字个数的功能
	int sum=0;
    for(int i=0;i<31;i++)
    {
        if(isdigit(arr[i]))
            sum+=1;
    }
      cout<<sum<<endl;  
}
void space_count(char arr[31]) {
    // 请在下面实现统计并输出空格个数的功能
	int sum=0;
    for(int i=0;i<31;i++)
    {
        if(arr[i]==' ')
        {
        	sum+=1;
        }
    }
     cout<<sum<<endl;   
}

int main() {
    char string[31];
    int i;
	
    cin.get(string,31);

    
    upper_case_count(string);
    lower_case_count(string);
    digit_count(string);
    space_count(string);
    return 0;
    
}
