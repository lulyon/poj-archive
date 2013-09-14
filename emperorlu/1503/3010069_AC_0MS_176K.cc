#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
char a[1000],b[1000],c[1000];
int main() 
{
    scanf("%s",b);
    if(strcmp(b,"0")==0)return 0;
    while(1) 
    {
        memset(c,'0',sizeof(c)); 
        scanf("%s",a);
        if(strcmp(a,"0")==0)break;
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
            b[lenb+1]='\0';
            for(int i=lenb;i>0;i--)
                b[i]=b[i-1];
            b[0]='1';
        }
    }
    printf("%s\n",b);
    //system("pause");
    return 0;
} 
