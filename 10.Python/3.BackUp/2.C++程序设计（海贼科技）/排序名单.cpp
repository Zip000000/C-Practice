#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct name
{
    char NAME[20];
};
int main() {
    name n[10];
    name temp;
    
    for(int i=0;i<10;i++)
    {
        scanf("%s",n[i].NAME);
    }
    
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(strcmp(n[i].NAME,n[j].NAME)>0)
            {
                strcpy(temp.NAME,n[j].NAME);
                strcpy(n[j].NAME,n[i].NAME);
                strcpy(n[i].NAME,temp.NAME);
            }
        }
    }
    cout<<n[0].NAME;
    for(int i=1;i<10;i++)
    {
        cout<<endl<<n[i].NAME;
    }

    return 0;
}