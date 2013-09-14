#include <iostream>
#include <stdlib.h>
using namespace std;
void mult(char a[],char b[],char s[])
{
     int i,j,k=0,alen,blen,sum=0,res[201][201]={0},flag=0;
     char result[201];
     alen=strlen(a);
     blen=strlen(b);

     for (i=0;i<alen;i++)
        for (j=0;j<blen;j++)
            res[i][j]=(a[i]-'0')*(b[j]-'0');

     for (i=alen-1;i>=0;i--)
         {
             for(j=blen-1;j>=0;j--)
                sum=sum+res[i+blen-j-1][j];
             result[k]=sum%10;
             k=k+1;
             sum=sum/10;
         }
     for (i=blen-2;i>=0;i--)
         {
             for(j=0;j<=i;j++)
                sum=sum+res[i-j][j];
             result[k]=sum%10;
             k=k+1;
             sum=sum/10;
         }
     if (sum!=0)
     {
            result[k]=sum;
            k=k+1;
     }
     for(i=0;i<k;i++)
        result[i]+='0';
     for(i=k-1;i>=0;i--)
        s[i]=result[k-1-i];
     s[k]='\0';
     while(1)
     {
         if (strlen(s)!=strlen(a)&&s[0]=='0')
             strcpy(s,s+1);
         else break;
     }
     return;
}

int main()
{
     char R[8],result[201],val[201];
     int n,dot,bit;
     int i,j,k,temp;
     while(cin>>R>>n)
     {
         dot=0;
         if(n==0)
         {
             cout<<1<<endl;
             continue;
         } 
         if(R[0]=='0'&&R[1]!='.')
         {
             for(i=0;R[i]=='0';i++);
             strcpy(R,&R[i]);
         }
         for(i=0;R[i]!='\0';i++)
         {
             if(R[i]=='.') 
             {
                 for(i=strlen(R)-1;R[i]=='0';i--) R[i]='\0';
                 break;
             }
         }
         if(R[0]=='.')
         {
             strcpy(val,R);
             R[0]='0';
             strcpy(&R[1],val);
         }
         for(i=0;R[i]!='\0';i++)
         {
             if(R[i]=='.')
             {
                 dot=strlen(R)-i-1;
                 strcpy(&R[i],&R[i+1]);
                 break;
             }
         }
         strcpy(result,R);
         for(i=1;i<n;i++)
         {
             mult(result,R,result);
         }
         bit=strlen(result);
         temp=bit-dot*n;
         if(dot!=0)
         {
             strcpy(val,&result[temp]);
             strcpy(&result[temp+1],val);
             result[temp]='.';
             result[bit+1]='\0';
         }    
         if(result[0]=='0'&&result[1]=='.')strcpy(result,&result[1]);
         cout<<result<<endl;
     }  
   return 0;
}
