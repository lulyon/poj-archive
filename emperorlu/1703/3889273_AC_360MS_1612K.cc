#include<iostream>
using namespace std;

int rank[100001];
int father[100001];
int opp[100001];

void make_set(int v){
	father[v]=v;
	rank[v]=0;
}

int find_set(int u){
	if(father[u]==u)
		return u;
	else{
		father[u]=find_set(father[u]);
		return father[u];
	}
}

int merge_set(int u,int v){
	if(u==-1)
		return v;
	else if(v==-1)
		return u;

	if(rank[u]>rank[v]){
		//u作为父节点
		father[v]=u;
		return u;
	}
	else{
		father[u]=v;
		if(rank[u]==rank[v])
			rank[v]++;
		return v;
	}
}//合并两个根节点  并返回新的根节点

void diff_group(int u,int v){
	//u和v是不同的集合
	int fa1=find_set(u);
	int fa2=find_set(v);
	int fa3=merge_set(opp[fa1],fa2);
	int fa4=merge_set(opp[fa2],fa1);
	opp[fa3]=fa4;
	opp[fa4]=fa3;
}

void init(int n){
	for(int i=0;i<=n-1;i++){
		rank[i]=0;
		father[i]=i;
		opp[i]=-1;
	}
}

void input(){
	int t;
	cin>>t;
	for(int i=0;i<=t-1;i++){
		int n,m;
		scanf("%d%d",&n,&m);
		getchar();
		init(n);
		char ch;
		int a,b;

		for(int j=0;j<=m-1;j++){
			ch=getchar();
			scanf("%d%d",&a,&b);
			getchar();

			if(ch=='A'){
				int x=find_set(a-1);
				int y=find_set(b-1);
				if(x==y)
					printf("In the same gang.\n");
				else if(x==opp[y])
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}//查询
			else
				diff_group(a-1,b-1);
		}
	}
}
int main(){
	input();
	return 0;
}