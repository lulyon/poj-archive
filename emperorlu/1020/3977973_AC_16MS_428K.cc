#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int cut[11],n,s,maxl,minl;
int map[41];

int min(int a,int b,int c)
{
    return a>(b>c?c:b)?(b>c?c:b):a;
}


int slove()
{
      int p=1,i,j,k;
      for(k=1;k<=10;k++) if(cut[k]!=0) {minl=k;break;}
      for(k=10;k>=1;k--) if(cut[k]!=0) {maxl=k;break;}
      if(maxl==1) return 1;
      bool sign1=1;
      for(k=1;k<=s;k++) if(map[k]!=s) {sign1=0;break;}
      if(sign1) return 1;
      for(i=1;i<=s;i++)
       {
         if(map[p]==0)break;
         if(map[i]<map[p]) p=i;
       }
       int pp=p,w=1;
       bool sign=1;
       while(sign){
                     if(pp<s&&map[pp]==map[pp+1]) {w++;pp++;}
                     else sign=0;
                   }
       for(i=min(s-map[p],w,maxl);i>=minl;i--)
        {//printf("(%d)",maxl);
           if(cut[i]!=0&&p+i-1<=s){
                         for(j=p;j<p+i;j++) map[j]+=i;
                         cut[i]--;
                         if(slove()) return 1;
                         else {
                              cut[i]++;
                              for(j=p;j<p+i;j++) map[j]-=i;
                              for(k=1;k<=10;k++) if(cut[k]!=0) {minl=k;break;}
                              for(k=10;k>=1;k--) if(cut[k]!=0) {maxl=k;break;}
                              }
                         }                   
        }
        return 0;
}
int main()
{
    int count;
    int i,j,k;
    cin>>count;
    while(count--)
    {
      int total=0;
      bool sign=0;
      cin>>s>>n;
      memset(cut,0,sizeof(cut));
      memset(map,0,sizeof(map));
      for(i=1;i<=n;i++)
       {
         cin>>k;
         total+=(k*k);
         cut[k]++;
       }
      
       if(s>40||total!=s*s) {printf("HUTUTU!\n");continue;}
       if(slove()) printf("KHOOOOB!\n");
        else  printf("HUTUTU!\n"); 
      }
      return 0;
}
