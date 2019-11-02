#include<iostream>
#include<string>
using namespace std;

int main()
{
    int y,m,d;
    int run=1;
    string input;
    cin>>input;
    string year,month,day;
    year=input.substr(0,4);

    
    if(input.size()==8)
    {
    	month=input.substr(5,1);
    	day=input.substr(7,1);
    }
    
    if(input.size()==9 && input[7]=='-')
    {
    	month=input.substr(5,2);
    	day=input.substr(7,1);       
    }
    
    if(input.size()==9 && input[6]=='-')
    {
    	month=input.substr(5,1);
    	day=input.substr(7,2);        
    }
    
    if(input.size()==10)
    {
    	month=input.substr(5,2);
    	day=input.substr(7,2);  
    }
    y=atoi(year.c_str()); 
    m=atoi(month.c_str()); 
    d=atoi(day.c_str());
    
    
    if(y%100==0 && y%400==0 || y%100!=0 && y%4==0)
        run=1;
    else
        run=0;
    
    if(m<1 || m>12)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        if(d<1 || d>31)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    else if(m==2)
    {
        if(run==1)
        {
            if(d<1 || d>29)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else
        {
            if(d<1 || d>28)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    else
    {
        if(d<1 || d>30)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
        cout<<"YES"<<endl;
        return 0;
}