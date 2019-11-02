#include <stdio.h>
int main() {
    int r=0,w=0,x=0;
    char input;
    while(scanf("%c",&input)!=EOF)
    {
         if(input=='\n')
         {
             break;
         }
        if(input=='r')
        {
            r=1;
        }
        if(input=='w')
        {
            w=1;
        }
        if(input=='x')
        {
            x=1;
        }
    }
    char op;
    while(scanf("%c%c",&op,&input)==2)
    {
        if(op=='+')
        {
            if(input=='r')
            {
                r=1;
            }
            if(input=='w')
            {
                w=1;
            }
            if(input=='x')
            {
                x=1;
            }
        }
        else if(op=='-')
        {
            if(input=='r')
            {
                r=0;
            }
            if(input=='w')
            {
                w=0;
            }
            if(input=='x')
            {
                x=0;
            }
        }
        char temp;
        scanf("%c",temp);
        
    }
	printf("%d",4*r+2*w+x);
    
    return 0;
}