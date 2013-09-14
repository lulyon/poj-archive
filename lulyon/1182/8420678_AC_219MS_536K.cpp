#include <iostream>
using namespace std;
struct node{int kind;}Tree[50010];
int root[50010];

void MakeSet(int n)
{
    for(int i = 0;i <= n;i++)
    {
        root[i] = i;
        Tree[i].kind = 0;
    }
}

int find(int index)
{
    int temp ;
    if(index == root[index]) return index;
    if(index != root[index])
    {
        temp = root[index];
        root[index] = find(root[index]);
    }
    Tree[index].kind = (Tree[temp].kind + Tree[index].kind) % 3;
    return root[index];
}
void Union(int a,int b,int value)
{
    root[b] = a;
   Tree[b].kind = value%3;
}

int main()
{
    int n,k,d,a,b,count = 0;// D是 1 表示同类， D 是 2表示 前吃后
    scanf("%d%d",&n,&k);
    MakeSet(n);
    for(int i = 0;i < k;i++)
    {
        scanf("%d%d%d",&d,&a,&b);
       if(a > n || b > n )
           count ++;
       else if( d == 2 && (a == b)) count ++;
       else
       {
           int t1 = find(a);
           int t2 = find(b);
           if(t1 != t2)
               Union(t1,t2,Tree[a].kind - Tree[b].kind+d-1+3);
           else 
           {
               int t3 = Tree[a].kind;
               int t4 = Tree[b].kind;
               if(d == 1 && t3 != t4) count ++;
               if(d == 2 && (t4 - t3 + 3)%3 != 1) count++;
           } 
       }//cout<<count<<endl;
    }
    
    printf("%d\n",count);
    return 0;
}

