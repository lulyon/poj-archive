#include <iostream>   
#include <queue>   
using namespace std;   
const int maxN=201;   
  
static int edge[maxN][maxN];   
bool visited[maxN];   
int father[maxN];   
int N, M; //±ßÊý,¶¥µãÊý   
int ans; //½á¹û   

void Ford_Fulkerson( )   
{   while(1)   
    {   //Ò»´Î´óÑ­»·,ÕÒµ½Ò»Ìõ¿ÉÄÜµÄÔö¹ãÂ·¾¶   
        queue <int> q;   
        memset(visited, 0, sizeof(visited));    memset(father, -1, sizeof(father));   
        int now;      visited[0] = true;       q.push(0);   
        while(!q.empty())//¹ã¶ÈÓÅÏÈ   
        {   now = q.front();     q.pop();   
            if(now == M-1) break;   
            for(int i=0; i<M; i++)   
            {    //Ã¿´Î¸¸Ç×½Úµã¶¼Òª¸üÐÂ,È¨Öµ¼õÎª0µÄ±ß¾Í²»ËãÁË.   
                if(edge[now][i] && !visited[i])   
                {   father[i] = now;     visited[i] = true;    q.push(i);   }   
            }   
        }   
        //¿ÉÄÜµÄÔö¹ãÂ·²»´æÔÚÁË   
        if(!visited[M-1]) break;   
        int u, min = 0xFFFF;   
        for(u=M-1; u; u=father[u])//ÕÒ³öÈ¨Öµ×îÐ¡µÄ±ß   
        {    if(edge[father[u]][u] < min)     min = edge[father[u]][u];     }   
        //¼õÈ¥×îÐ¡È¨Öµ   
        for(u=M-1; u; u=father[u])   
        {    edge[father[u]][u] -= min;   //Ç°Ïò»¡¼õÈ¥
            //ºóÏò»¡¼ÓÉÏ   
            //´æÔÚÔ²»·,Õâ¾ä»°¹Ø¼ü   
            edge[u][father[u]] += min;   
        }             
        ans+=min;   //µ±Ç°Ôö¹ãÂ·¾¶Ôö¼ÓµÄÁ÷
    }   
}   
  
int main()   
{   int s, e, w;   
    //while(cin >> N >> M)   
    while(scanf("%d%d", &N, &M)!=EOF)
    {   ans=0;   
        memset(edge, 0, sizeof(edge));   
        for(int i=0; i<N; i++)   
        //{   cin>>s>>e>>w;         edge[s-1][e-1]+=w;      }   
        {scanf("%d%d%d",&s, &e, &w); edge[s-1][e-1]+=w;}
        Ford_Fulkerson();   
        //cout << ans << endl;   
        printf("%d\n",ans);
        
    }   
    return 0;   
}

