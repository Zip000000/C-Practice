#include <stdio.h>
#include <string.h>
struct struct_name
{
  char name[20]; 
};
int main() {
    struct struct_name student[10];
    for(int i=0;i<10;i++)
    {
        scanf("%s",&student[i].name);
    }
	for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(strcmp(student[i].name,student[j].name)>0)
            {
                char temp_name[10];
                strcpy(temp_name,student[i].name);
                strcpy(student[i].name,student[j].name);
                strcpy(student[j].name,temp_name);
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%s\n",student[i].name);
    }

    return 0;
}