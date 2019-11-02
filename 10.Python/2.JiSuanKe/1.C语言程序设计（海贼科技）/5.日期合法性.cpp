#include <stdio.h>

int main()
{
	int y,m,d;
    scanf("%d-%d-%d",&y,&m,&d);
    int run;
    if(y%100!=0 && y%4==0 || y%400 == 0)
        run=1;  //run
    else 
        run=0;
    
    if((m==1||m==3||m==5||m==7||m==8||m==10||m==12) && (d>=1 && d<=31))
    {
        printf("YES");
    }
    else if(m==2 && run==1 && d>=1 && d<=29 || m==2 && run==0 && d>=1 &&d<=28)
    {
        printf("YES");
    }
    else if((m==4||m==6||m==9||m==11) && m<=12 && d>=1 && d<=30)
    {
    	printf("YES");
    }
    else
    {
        printf("NO");
    }
	return 0;
}