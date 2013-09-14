#include <iostream>   
#include <cstring>   
using namespace std;   
  
const int N = 128;   
const int INF = (1<<30)-1;   
  
int  adj[N][N];   
int lev[N];   
int val[N];   
int V[N];   
  
int m;//等级差距   
int littleLev, bigLev;//本次dijkstra的最低与最高等级   
  
/*s为源点,n为顶点数*/  
int dijkstra(int s, int n){   
    bool is[N];    
    int pre = s;   
           
    memset(is,false,sizeof(is));   
    for(int i=0;i<n;i++)   
        V[i]=INF;;   
     is[s]=true, V[s]=0;   
     for(int j=0;j<n-1;j++){   
            int min=INF,id;   
         for(int i=0;i<n;i++) if(!is[i])    
            if(lev[i]>=littleLev && lev[i]<=bigLev)//去掉这个等级约束就是标准的单源最短路径   
            {   
             if(V[i] > V[pre] + adj[pre][i])   
                 V[i] = V[pre] + adj[pre][i];   
                if(min > V[i])   
                    min = V[id=i];   
            }   
        if(min!=INF)//加入新点   
            pre=id, is[id]=true;   
        else//表示有些点不可达   
            break;   
    }   
    int min = INF;   
    for(int i=0;i<n;i++) if(V[i]!=INF)//求最短路时需要加上最下层物品价格   
        if(min > V[i] + val[i])   
            min=V[i] + val[i];   
    return min;   
}   
  
int main()   
{   
    int n;   
  
    cin >> m >> n;   
    for(int i=0;i<n;i++)   
        for(int j=0;j<n;j++)   
         adj[i][j]=(i==j) ? 0 : INF;//除对角边其它应该初始为无穷大   
    for(int i=0;i<n;i++){   
        int c, dis, id;   
        cin >> val[i] >> lev[i] >> c;   
        for(int j=0;j<c;j++){   
            cin >> id >> dis;   
         adj[i][id-1]=dis;//有向图这点注意   
     }   
    }   
    int min=INF,ans;   
    for(int i=lev[0]-m;i<=lev[0];i++){//枚举所有等级范围   
        littleLev = i;   
        bigLev = i+m;   
        ans=dijkstra(0,n);   
        if(min > ans)   
            min=ans;   
    }   
    cout << min << endl;   
       
    return 0;   
}  
