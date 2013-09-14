#include<iostream>
using namespace std;
char a[110][110];
bool b[110][110];
void find(int i,int j)
{
    b[i][j]=1;
    if(a[i][j-1]=='W'&&b[i][j-1]==0)find(i,j-1);
    if(a[i+1][j-1]=='W'&&b[i+1][j-1]==0)find(i+1,j-1);
    if(a[i+1][j]=='W'&&b[i+1][j]==0)find(i+1,j);
    if(a[i+1][j+1]=='W'&&b[i+1][j+1]==0)find(i+1,j+1);
    if(a[i][j+1]=='W'&&b[i][j+1]==0)find(i,j+1);
    if(a[i-1][j+1]=='W'&&b[i-1][j+1]==0)find(i-1,j+1);
    if(a[i-1][j]=='W'&&b[i-1][j]==0)find(i-1,j);
    if(a[i-1][j-1]=='W'&&b[i-1][j-1]==0)find(i-1,j-1);
}
int main()
{
    int m,n,i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%s",&a[i][1]);
    int cn=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i][j]=='W'&&b[i][j]==0)
            {
                find(i,j);
                cn++;
            }
        }
    printf("%d\n",cn);
    //system("pause");
    return 0;
}
