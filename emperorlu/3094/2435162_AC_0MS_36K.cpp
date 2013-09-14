#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    long sum;
    char a[300];
    while((gets(a),a[0])!='#')
    {
        for(i=0,sum=0;i<strlen(a);i++)
        {
            if(a[i]==' ')continue;
            else sum+=(i+1)*(a[i]-'A'+1);
        }
        printf("%ld\n",sum);            
    }
    return 0;
}
