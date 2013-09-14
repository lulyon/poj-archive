#include<iostream>
#include<algorithm>

const int maxn = 110;

int a[maxn][maxn];

int parent[maxn];


typedef struct{
	int org, dest;
	int weight;
}EdgeType;

EdgeType Info[maxn*maxn];

bool cmp(const EdgeType &s, const EdgeType &t){
	if(s.weight<=t.weight)return 1;
	else return 0;
}

void initUnionSet(int n){
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
}

int root(int i){
	int r = i;
	while(r != parent[r]){
		r = parent[r];
	}

	int tmp;
	while(i != r){
		tmp = parent[i];
		parent[i] = r;
		i = tmp;
	}
	return r;
}

void merge(int i, int j){
	parent[i] = j;
}


int main(){
	int n, Q;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d", &Q);
	int index1, index2;
	while(Q--){
		scanf("%d %d", &index1, &index2);
		a[index1][index2] = 0;
		a[index2][index1] = 0;
	}

	int top = 0;
	for(int i=1; i<=n; ++i){
		for(int j=i+1; j<=n; ++j){
			Info[top].org = i;
			Info[top].dest = j;
			Info[top].weight = a[i][j];
			top++;
		}
	}
	std::sort(Info, Info+top, cmp);
	initUnionSet(n);

	int index = 0,sum=0;
	for(int t=1; t<n; ++t){
		while(1){
			int i = Info[index].org;
			int j = Info[index].dest;

			int ri = root(i);
			int rj = root(j);

			if(ri!=rj){
				merge(ri, rj);
				sum += Info[index].weight;
				break;
			}

			index++;
		}
	}
	printf("%d\n", sum);
}
