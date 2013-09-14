#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct tel
{
   int p;
   char a[1000];
}num[1000];
int cmp ( const void *m , const void *n) 
{ 
    return strcmp( (*(tel *)m).a , (*(tel *)n).a); 
} 
void delete1 (char a[])
{
    int i,j,q;
    for(i=0;a[i]!='\0';i++)
    {
       if(a[i]=='-') 
       {
           for(j=i;a[j+1]!='\0';j++)
           a[j]=a[j+1];
           a[j]='\0';
       }
    }
}
int main()
{
    int i,j,m,len,count=0;
    scanf("%d",&m);
       for(i=0;i<m;i++)
       {
           num[i].p=1;
           scanf("%s",num[i].a);
           delete1(num[i].a);
           for(j=0;num[i].a[j]!='\0';j++)
           {
           if(num[i].a[j]=='A'||num[i].a[j]=='B'||num[i].a[j]=='C') num[i].a[j]='2';
           if(num[i].a[j]=='D'||num[i].a[j]=='E'||num[i].a[j]=='F') num[i].a[j]='3';
           if(num[i].a[j]=='G'||num[i].a[j]=='H'||num[i].a[j]=='I') num[i].a[j]='4';
           if(num[i].a[j]=='J'||num[i].a[j]=='K'||num[i].a[j]=='L') num[i].a[j]='5';
           if(num[i].a[j]=='M'||num[i].a[j]=='N'||num[i].a[j]=='O') num[i].a[j]='6';
           if(num[i].a[j]=='P'||num[i].a[j]=='R'||num[i].a[j]=='S') num[i].a[j]='7';
           if(num[i].a[j]=='T'||num[i].a[j]=='U'||num[i].a[j]=='V') num[i].a[j]='8';
           if(num[i].a[j]=='W'||num[i].a[j]=='X'||num[i].a[j]=='Y') num[i].a[j]='9';
           }
       }
       for(i=0;i<m-1;i++)
       for(j=i+1;j<m;j++)
       {
       if(num[i].p!=-1)
       {
          if(strcmp(num[i].a,num[j].a)==0)
          {
             num[i].p++;
             num[j].p=-1;
             count++;
          }  
       }
       }
       qsort(num,m,sizeof(num[0]),cmp);
       if(count==0) printf("No duplicates.");
       else for(i=0;i<m;i++)
       {
         if(num[i].p>=2)
         {
             len=strlen(num[i].a);
             for(j=0;j<len;j++)
             {
								 if(j==3)printf("-");
								 printf("%c",num[i].a[j]);
						 }
             printf(" %d\n",num[i].p);
         }
       }
    return 0;  
}
