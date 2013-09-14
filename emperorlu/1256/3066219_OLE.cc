#include <iostream>
using namespace std;
char prechar[20],nowchar[20],a[20],init[20],upstack[20],lowstack[20];
int Row[15];
//用于模拟棋盘，其中数组下标为行号，所赋的值为棋子所在的列号
int i;
int CanSet(int k)
//判断第k行上棋子能否放在当前列上
{
    int j;
    j=1;
    while(j<k)
    {
        if(Row[j]==Row[k])return 0;
        //只要和前边的行上的棋子有冲突便不成功
        j++;
    }
    return 1;
}
void QuanPaiLie(int n)
//////全排列实现函数
{

    int k;
    Row[1]=0;
    ////第1次，第1行上也没放置棋子
    k=1;/////开始放置第1行
    int flag=0;
    while(k>0)
    {
        Row[k]=Row[k]+1;
        ////将棋子向右移动一格
        while(Row[k]<=n&&(CanSet(k)<1))
        {
            Row[k]=Row[k]+1;
            ////不能放则重复向右移动棋子
        };
        if(Row[k]<=n)
        ////我们找到了一个位置，那么可以放下棋子了
        {
            if(k==n)
            {
                if(flag==0)
                {
                    for(i=1;i<=n;i++)
                    {
                        prechar[i]=a[Row[i]];
                        printf("%c",a[Row[i]]);
                    }
                    prechar[n+1]='\0';
                    printf("\n");
                    
                }
                else
                {
                    for(i=1;i<=n;i++)
                        nowchar[i]=a[Row[i]];
                    nowchar[n+1]='\0';
                    if(strcmp(prechar+1,nowchar+1))
                        printf("%s\n",nowchar+1);
                }
                flag++;
            }
            else
            {
                k=k+1;////如果还没有放完，继续放
                Row[k]=0;////从最左边开始放
            }
        }
        else
        {
            k=k-1;
            /////向上一行，看看是否有别的放法
        }
    }
}
int main()
{ 
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",init);
        int upflag=0,lowflag=0;
        for(i=0;init[i];i++)
        {
            if(init[i]>='A'&&init[i]<='Z')
                upstack[upflag++] = init[i];
            else
                lowstack[lowflag++] = init[i];
        }
        n = i;
        sort(upstack,upstack+upflag);
        sort(lowstack,lowstack+lowflag);
        int lflag=0,uflag=0;
        for(i=1;i<=n;i++)
        {       
            if(uflag==upflag||lowstack[lflag]<upstack[uflag]+32)
            {
                a[i]=lowstack[lflag];
                lflag++;
            }
            else
            {
                a[i]=upstack[uflag];
                uflag++;
            }
        }
        a[n+1]='\0';
        //cout<<a+1<<endl;
        //system("pause");
        QuanPaiLie(n);
    }
    return 0;
}
