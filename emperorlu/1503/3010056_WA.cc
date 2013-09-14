#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
char a[200],b[200],c[200];
int main() 
{
    scanf("%s",b); 
    while(1) 
    {
        memset(c,'0',sizeof(c)); 
        scanf("%s",a);
        if(a[0]=='0')break;
        int lena=strlen(a);
        int lenb=strlen(b); 
        int len=lena-lenb; 
        if(len>=0) 
            strcpy(&c[len],b); 
        else 
        { 
            len=-len; 
            strcpy(&c[len],a); 
            strcpy(a,b); 
        } 
        memset(b,'0',sizeof(b)); 
        int i=strlen(a)-1; 
        b[i+1]='\0'; 
        b[i]=(a[i]-'0'+c[i]-'0')%10+'0'; 
        for(i--;i>=0;i--) 
        { 
            a[i]+=(a[i+1]-'0'+c[i+1]-'0')/10; 
            b[i]=(a[i]-'0'+c[i]-'0')%10+'0'; 
        } 
        char p; 
        p=(a[0]-'0'+c[0]-'0')/10+'0'; 
        if(p=='1')
        {
            printf("1"); 
            printf("%s\n",b);
            for(int i=lenb;i>0;i--)
                b[i]=b[i-1];
            b[0]='1';
        }
    }
    printf("%s\n",b);
    //system("pause");
    return 0;
} 
