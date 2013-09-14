#include<stdio.h>
int main()
{
    char a;
    while((a=getchar())!=EOF)
    {
        if(a>='0'&&a<='9')
        {
            printf("%d\n",a+1-'0');
        }
        else if(a>='A'&&a<='Z')
        {
            printf("%d\n",a-'A'+11);
        }
        else if(a>='a'&&a<='z')
        {
            printf("%d\n",a-'z'+61);
        }
        else 
        {
          printf("such number is impossible!\n");
        }
    }
    return 0;
}
