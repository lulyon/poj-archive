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
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(!m&&!n)break;
        for(i=1;i<=m;i++)
            scanf("%s",&a[i][1]);
        /*
        for(int ii=1;ii<=m;ii++)
        {
            for(int jj=1;jj<=n;jj++)
                cout<<a[ii][jj];
            cout<<endl;
        }
        system("pause");
        */
        memset(b,0,sizeof(b));
        int cn=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                if(a[i][j]=='W'&&b[i][j]==0)
                {
                    find(i,j);
                    /*
                    for(int ii=1;ii<=m;ii++)
                    {
                        for(int jj=1;jj<=n;jj++)
                            cout<<b[ii][jj];
                        cout<<endl;
                    }
                    system("pause");
                    */
                    cn++;
                }
            }
        printf("%d\n",cn);
    }
    return 0;
}
