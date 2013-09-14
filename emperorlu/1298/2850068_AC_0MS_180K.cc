#include<stdio.h> 
#include<string.h> 
void f(char *b) 
{ 
    for(int i=0;b[i];i++) 
    { 
        if(b[i]>='F'&&b[i]<='Z') 
            b[i]-=5; 
        else if(b[i]>='A'&&b[i]<='E') 
            b[i]+=21; 
    }
} 

int main() 
{ 
    char a[20],b[1000],c[10]; 
    while((gets(a),strcmp(a,"START"))==0) 
    { 
        gets(b); 
        f(b); 
        printf("%s\n",b); 
        gets(c); 
    } 
    return 0; 
}