#include<stdio.h> 
#include<memory.h> 
#include<stdlib.h> 
#include<string.h> 
int main() 
{ 
    int t,cn=1; 
    scanf("%d",&t); 
    while(t--) 
    { 
        char a[87],b[87],c[87]; 
        memset(c,'0',sizeof(c)); 
        scanf("%s%s",a,b); 
        int len=strlen(a)-strlen(b); 
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
        b[i]=(a[i]-'0'+c[i]-'0')%2+'0'; 
        for(i--;i>=0;i--) 
        { 
            a[i]+=(a[i+1]-'0'+c[i+1]-'0')/2; 
            b[i]=(a[i]-'0'+c[i]-'0')%2+'0'; 
        } 
        char p; 
        p=(a[0]-'0'+c[0]-'0')/2+'0'; 
        printf("%d ",cn++);
        if(p=='1')
		{
			printf("1");
			printf("%s\n",b);
		}
		else
		{
			for(i=0;b[i];i++)
			{
				if(b[i]!='0')
				{
					printf("%s\n",b+i);
					break;
				}
			}
			if(b[i]=='\0')printf("0\n");
		}
    }
    return 0; 
}
