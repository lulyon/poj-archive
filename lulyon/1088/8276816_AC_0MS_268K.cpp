#include<iostream>
using namespace std;

typedef struct INFO{
	int h;
	int length;
}InfoType;

InfoType a[110][110];
int r,c;

void dfs(int i,int j){
	
	if(a[i][j].length>1)return;
	
	int maxlength = 0;
	
	if(i-1>=0){
		if(a[i][j].h>a[i-1][j].h){
			dfs(i-1,j);
			if(maxlength<a[i-1][j].length)maxlength = a[i-1][j].length;
		}
	}
	if(i+1<r){
		if(a[i][j].h>a[i+1][j].h){
			dfs(i+1,j);
			if(maxlength<a[i+1][j].length)maxlength = a[i+1][j].length;
		}
	}
	if(j-1>=0){
		if(a[i][j].h>a[i][j-1].h){
			dfs(i,j-1);
			if(maxlength<a[i][j-1].length)maxlength = a[i][j-1].length;
		}
	}
	if(j+1<r){
		if(a[i][j].h>a[i][j+1].h){
			dfs(i,j+1);
			if(maxlength<a[i][j+1].length)maxlength = a[i][j+1].length;
		}
	}
	
	a[i][j].length = maxlength+1;
}

int main(){

	scanf("%d%d",&r,&c);
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			scanf("%d",&a[i][j].h);
			a[i][j].length=1;
		}
	}
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			dfs(i,j);
		}
	}
	int maxlength=-1;
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if(maxlength<a[i][j].length)
				maxlength = a[i][j].length;
		}
	}
	
	printf("%d\n",maxlength);
	return 0;
}

