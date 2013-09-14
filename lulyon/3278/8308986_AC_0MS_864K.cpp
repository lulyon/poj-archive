#include<iostream>
using namespace std;

int visited[100010];

typedef struct QUEUE{
	int index[100010];
	int begin, end;
}queue;

queue Q;

int bfs(int n,int k){
	Q.begin=Q.end=0;
	Q.index[0]=n;
	visited[n]=0;
	int index;
	while(Q.begin<=Q.end){
		index = Q.index[Q.begin++];
		if(index==k)return visited[index];
		if((index+1)<=k+1 && visited[index+1]==0){
			visited[index+1] = visited[index]+1;
			Q.index[++Q.end]=index+1;
		}
		if((index-1)>=0 && (index-1)!=n && visited[index-1]==0){
			visited[index-1] = visited[index]+1;
			Q.index[++Q.end]=index-1;
		}
		if((2*index)<=k+1 && (2*index)!=n && visited[2*index]==0){
			visited[2*index] = visited[index]+1;
			Q.index[++Q.end]=2*index;
		}
	}
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k<=n){
		printf("%d\n",n-k);
	}
	else{
		printf("%d\n",bfs(n,k));
	}
	//system("pause");
	return 0;
}

