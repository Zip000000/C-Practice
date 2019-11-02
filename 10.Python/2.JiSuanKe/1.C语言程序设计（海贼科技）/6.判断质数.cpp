#include <stdio.h>
int is_znum(int num)
{
    if(num==2)
    {
        return 1;
    }
    else
    {
        for(int i=2;i<num;i++)
        {
            if(num%i == 0 && num!=i)
            {
                return 0;
            }
        }
        return 1;
    }
    
}
int main() {
    int num;
    scanf("%d",&num);
    if(is_znum(num))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}