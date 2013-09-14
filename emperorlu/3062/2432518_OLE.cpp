#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    while((gets(a),a[0])!=EOF)
    {
        printf("%s\n",a);
    }
        return 0;    
}
