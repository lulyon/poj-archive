#include<iostream>
using namespace std;
int n,m;

int ufset[50010];
bool visited[50010];

void init(){
	for(int i=1; i<=n; ++i){
		ufset[i]=i;
	}
}

int ufset_root(int index){
	int p=index;
	while(ufset[p] !=p){
		p = ufset[p];
	}
	int parent;
	while(ufset[index]!=p){
		parent = ufset[index];
		ufset[index]=p;
		index = parent;
	}
	return p;
}

void ufset_union(int i, int j){
	int ir = ufset_root(i);
	int jr = ufset_root(j);
	
	if(ir!=jr)ufset[jr] = ir;
}



int main(){
	int t=0;
	while(1){
		scanf("%d%d",&n,&m);
		if(n==0 && m==0)break;
		printf("Case %d: ",++t);
		init();
		
		int i,j;
		while(m--){
			scanf("%d%d", &i, &j);
			ufset_union(i,j);
		}
		for(int i=1; i<=n; ++i){
			visited[i]=0;
		}
		for(int i=1; i<=n; ++i){
			visited[ufset_root(i)]=1;
			//printf("%d ",ufset_root(i));
		}
		//system("pause");
		int cnt=0;
		for(int i=1; i<=n; ++i){
			if(visited[i]==1)cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}

