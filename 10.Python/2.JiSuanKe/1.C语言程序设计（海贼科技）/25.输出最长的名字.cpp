#include <stdio.h>
#include <string.h>
struct stdd
{
    char name[100];
    int length;
};

int main() {
    int n;
    scanf("%d", &n);
    struct stdd student[n];
    char temp;
    scanf("%c",&temp);
    if(temp=='\n');
    char input;
    for(int i=0;i<n;i++)
    {
    	int count=0;
        while(scanf("%c",&input) != EOF)
        {
			if(input!='\n')
			{
				student[i].name[count]=input;
	            count++;
			}
			else
			{
				student[i].length=count;
				break;
			}
        }
    }
    int max_i=0;
    for(int i=0;i<n;i++)
    {
        if(student[i].length>student[max_i].length)
        {
            max_i=i;
        }
    }
    for(int i=0;i<student[max_i].length;i++)
    {
        printf("%c",student[max_i].name[i]);
    }
    

    return 0;
}
