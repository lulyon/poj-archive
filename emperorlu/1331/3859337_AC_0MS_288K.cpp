#include <iostream>
using namespace std;

long numberConverter(char *p, int b)
{ //将字符串p中的值转换为b进制的形式
  long sum = 0;
 for(int i=0; p[i]!='\0'; i++)
  sum = sum*b+p[i]-'0';
 return sum; 
}


int biggestNumber(char *p, char *q, char *r)
{ //寻找p，q，r包含的字符中最大的数值
  int big = 0;
  for(int i=0; p[i] != '\0'; i++)
  if(p[i]-'0' > big)
      big = p[i]-'0';
    for(int i=0; q[i] != '\0'; i++)
  if(q[i]-'0' > big)
      big = q[i]-'0';
    for(int i=0; r[i] != '\0'; i++)
  if(r[i]-'0' > big)
      big = r[i]-'0';
    return big;
}


int main()
{
  int n;
 cin>>n;
 char p[8],q[8],r[8];
 while(n--)
 {
   cin>>p>>q>>r;
   int tag = 0;
  int big = biggestNumber(p,q,r);
  for(int i=big+1; i<=16; i++)
   if(numberConverter(p,i)*numberConverter(q,i) == numberConverter(r,i))
   {    
        cout<<i<<endl;     
        tag = 1;
        break;
   }
  if(tag == 0)
        cout<<"0"<<endl;
    }  
    return 0;
}