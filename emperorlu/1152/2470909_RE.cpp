#include<stdio.h>
#include<string.h>
int main()
{
    char a[1];
    while((gets(a),a[0])!=EOF)
    {
        if(a[0]>='0'&&a[0]<='9')
        {
            printf("%d\n",a[0]+1-'0');
        }
        else if(a[0]>='a[0]'&&a[0]<='Z')
        {
            printf("%d\n",a[0]-'a[0]'+11);
        }
        else if(a[0]>='a[0]'&&a[0]<='z')
        {
            printf("%d\n",a[0]-'z'+61);
        }
        else 
        {
          printf("such number is impossible!\n");
        }
    }
    return 0;
}
