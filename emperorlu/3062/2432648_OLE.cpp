#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    leap:gets(a);  
    printf("%s\n",a);
    goto leap;
    return 0;    
}
