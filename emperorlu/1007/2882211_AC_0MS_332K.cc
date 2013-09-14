#include<iostream>
#include<algorithm>
#define N 51
#define M 100
using namespace std;
char str[M][N];

struct node
{
 int num;
 char *p;
}a[M];

inline bool less(struct node a,struct node b) //只需告诉其排序的原则
{
 return a.num<b.num; 
}
int main()
{
	bool less(struct node a,struct node b);
 int m,n;
 int i,j,k;
 while(cin>>n>>m)
 {
  for(i=0;i<m;i++)
  {
   cin>>str[i];
   a[i].p=str[i]; //用指针指向字符串
   a[i].num=0;
   for(j=0;j<n-1;j++)
    for(k=j+1;k<n;k++)
     if(str[i][j]>str[i][k])
      a[i].num++;
  }
  sort(a,a+m,less);
  for(i=0;i<m;i++)
   cout<<a[i].p<<endl;

 }
}
