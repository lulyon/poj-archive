#include<iostream>
using namespace std;

int a[310][310];

typedef struct QUEUE{
	int iindex[310*310];
	int jindex[310*310];
	int begin, end;
}queue;

queue Q;

int bfs(int is, int js, int ie, int je, int n){
	Q.iindex[0]=is;
	Q.jindex[0]=js;
	Q.begin = Q.end = 0;
	a[is][js]=0;
	
	int i,j;
	while(Q.begin<=Q.end){
		i = Q.iindex[Q.begin];
		j = Q.jindex[Q.begin];
		Q.begin++;
		
		if(i==ie && j==je)return a[ie][je];
		
		if((i-1)>=0 &&  (j-2)>=0 && (i-1!=is || j-2!=js) && a[i-1][j-2]==0){
			a[i-1][j-2]=a[i][j]+1;
			Q.end++;
			Q.iindex[Q.end]=i-1;
			Q.jindex[Q.end]=j-2;
		}
		if((i-1)>=0 && (j+2)<n && (i-1!=is || j+2!=js) && a[i-1][j+2]==0){
			a[i-1][j+2]=a[i][j]+1;
			Q.end++;
			Q.iindex[Q.end]=i-1;
			Q.jindex[Q.end]=j+2;
		}
		if((i-2)>=0 && (j-1)>=0 && (i-2!=is || j-1!=js) && a[i-2][j-1]==0){
			a[i-2][j-1]=a[i][j]+1;
			Q.end++;
			Q.iindex[Q.end]=i-2;
			Q.jindex[Q.end]=j-1;
		}
		if((i-2)>=0 && (j+1)<n && (i-2!=is || j+1!=js) && a[i-2][j+1]==0){
			a[i-2][j+1]=a[i][j]+1;
			Q.end++;
			Q.iindex[Q.end]=i-2;
			Q.jindex[Q.end]=j+1;
		}
		if((i+1)<n && (j-2)>=0 && (i+1!=is || j-2!=js) && a[i+1][j-2]==0){
			a[i+1][j-2]=a[i][j]+1;
			Q.end++;
			Q.iindex[Q.end]=i+1;
			Q.jindex[Q.end]=j-2;
		}
		if((i+1)<n && (j+2)<n && (i+1!=is || j+2!=js) && a[i+1][j+2]==0){
			a[i+1][j+2]=a[i][j]+1;
			Q.end++;
			Q.iindex[Q.end]=i+1;
			Q.jindex[Q.end]=j+2;
		}
		if((i+2)<n && (j-1)>=0 && (i+2!=is || j-1!=js) && a[i+2][j-1]==0){
			a[i+2][j-1]=a[i][j]+1;
			Q.end++;
			Q.iindex[Q.end]=i+2;
			Q.jindex[Q.end]=j-1;
		}
		if((i+2)<n && (j+1)<n && (i+2!=is || j+1!=js) && a[i+2][j+1]==0){
			a[i+2][j+1]=a[i][j]+1;
			Q.end++;
			Q.iindex[Q.end]=i+2;
			Q.jindex[Q.end]=j+1;
		}
	}
	return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				a[i][j]=0;
			}
		}
		
		int is,js,ie,je;
		scanf("%d%d%d%d",&is,&js,&ie,&je);
		if(is==ie && js==je){
			printf("0\n");
			continue;
		}
		printf("%d\n",bfs(is, js, ie, je, n));
	}
	return 0;
}

