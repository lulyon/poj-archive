#include<iostream>
using namespace std;

#define NUM 10

char str[20];

/*字典树的数据结构*/

struct trie
{
   trie * next[NUM];
   bool isword;
};

/*字典树的数据结构*/

/*字典树的相关操作*/

trie thead,*t,*s;
trie tttt[1000000];
int top;
void inittrie(trie &head) //建树
{
   int i;
   for(i=0;i<NUM;i++)
       head.next[i]=NULL;
   head.isword=false;
}

bool exist(trie &head,char x[]) //判断字符串是否存在
{
   int i;
   int len;
   len=strlen(x);
   if(len==0) return false;
   s=&head;
   for(i=0;i<len;i++)
   {
       if(s->next[x[i]-'0']==NULL) break;
       else s=s->next[x[i]-'0'];
   }
   if(i==len && s->isword==true) return true;
   else return false;
}

int insert(trie &head,char x[]) //插入字符串
{
   int i,j;
   int len;
   len=strlen(x);
   s=&head;
   for(i=0;i<len;i++)
   {
       if(s->next[x[i]-'0']==NULL) break;
       else s=s->next[x[i]-'0'];
   }
   if(i==len)
   {
       s->isword=true;
       return true;
   }
   for(;i<len;i++)
   {
       //t=(trie*)malloc(sizeof(trie));
       t=&tttt[top++];
       //new trie;
       for(j=0;j<NUM;j++) t->next[j]=NULL;
       t->isword=false;
       s->next[x[i]-'0']=t;
       s=t;
   }
   s->isword=true;
   return false;
}

void deltrie(trie *current)//删除字典树
{
   int i;
   for(i=1;i<NUM;i++)
   {
       if(current->next[i]==NULL) continue;
       deltrie(current->next[i]);
   }
   free(current);
   current=NULL;
}

/*字典树的相关操作*/
bool visit(trie *head)
{
    if(head->isword)return 1;
    for(int i=0;i<NUM;++i)
        if(head->next[i]!=NULL&&visit(head->next[i]))return 1;
    return 0;
}

bool check(trie *head)
{
    int i;
    s=head;
    
    if(s->isword)
    {
        for(i=0;i<NUM;++i)
        {
            if(s->next[i]!=NULL&&visit(s->next[i]))return 1;
        }
    }
    
    for(i=0;i<NUM;++i)
    {
        if(s->next[i]!=NULL)
        {
            if(check(s->next[i]))return 1;
        }
    }
    return 0;
}

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        inittrie(thead);
        scanf("%d",&n);
        top=0;
        for(int i=0;i<n;++i)
        {
            scanf("%s",str);
            insert(thead,str);
        }
        if(check(&thead))
            printf("NO\n");
        else
            printf("YES\n");
       // deltrie(&thead);
    }
    return 0;
}
