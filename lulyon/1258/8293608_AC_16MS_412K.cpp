#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 510;

int a[maxn][maxn];

typedef struct INFO{
	int value;
	int i;
	int j;
}InfoType;
InfoType edge[maxn*maxn];

typedef struct UFSET{
	int parent;
}ufset;

ufset vertex[maxn];

int root(int a){
	int r=a;
	while(vertex[r].parent!=r){
		r = vertex[r].parent;
	}
	int tmp;
	while(vertex[a].parent!=r){
		tmp = vertex[a].parent;
		vertex[a].parent = r;
		a=tmp;
	}
	return r;
}

void merge(int a, int b){
	int ra = root(a);
	int rb = root(b);
	if(ra!=rb)vertex[rb].parent=ra;
}

bool differ(int a,int b){
	int ra = root(a);
	int rb = root(b);
	if(ra!=rb)return 1;
	else return 0;
}

int cmp(const InfoType &a, const InfoType &b){
	if(a.value<=b.value)return 1;
	else return 0;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		int edgeNum=0;
		for(int i=1; i<=n; ++i){
			for(int j=i+1; j<=n; ++j){
				edge[edgeNum].value = a[i][j];
				edge[edgeNum].i = i;
				edge[edgeNum].j = j;
				edgeNum++;
			}
		}
		
		for(int i=1; i<=n; ++i){
			vertex[i].parent=i;
		}
		sort(edge, edge+edgeNum, cmp);
		
		int sum=0;
		for(int k=0; k<edgeNum; ++k){
			int i = edge[k].i;
			int j = edge[k].j;
			int value = edge[k].value;
			
			if(differ(i,j)){
				merge(i,j);
				sum += value;
			}
		}
		printf("%d\n",sum);
		
	}
	return 0;
}

