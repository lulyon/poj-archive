#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char a[26],b[80];
    gets(a);
    gets(b);
    for(i=0;b[i]!='\0'&&i<80;i++)
    {
        if(b[i]>='a'&&b[i]<='z')b[i]=a[b[i]-'a'];
        if(b[i]>='A'&&b[i]<='Z')b[i]=a[b[i]-'A']-32;
        printf("%c",b[i]);
    }
    return 0;
}
