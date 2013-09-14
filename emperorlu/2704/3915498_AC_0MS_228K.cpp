#include <iostream>
using namespace std;

char matrix[64][64];
long long a[64][64];
int n;


bool Input()
{
  scanf("%d",&n);
   if(n==-1)return false;
  int i,j;
  for(i=0;i<n;i++)
  {
    scanf("%s",matrix[i]);
    for(int j=0;j<n;++j)
    	a[i][j]=0;
  }
   return true;     
}

void Solve()
{
    a[n-1][n-1]=1;
    int i,j;
    for(i=n-1;i>=0;i--)
     for(j=n-1;j>=0;j--)
      {
        if(i+matrix[i][j]-'0'<n)
         a[i][j]+=a[i+matrix[i][j]-'0'][j];
         
        if(j+matrix[i][j]-'0'<n)
         a[i][j]+=a[i][j+matrix[i][j]-'0']; 
         
         a[n-1][n-1]=1;
      }
      
  printf("%lld\n",a[0][0]);
}
int main()
{
  while(Input())
   Solve();    
    return 0;
}
