#include<iostream>
using namespace std;

typedef struct INFO{
	int h;      //(i,j)点的高度 
	int length;//保存以(i,j)为起点的最大滑雪长度 
}InfoType;

InfoType a[110][110];
int r,c;

void dfs(int i,int j){
	
	if(a[i][j].length>1)return; //已经求出最大滑雪长度的不必再搜了，剪掉
	
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
			a[i][j].length=1;//(i,j)为起点的最大滑雪长度的初始值为1 
		}
	}
	
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			dfs(i,j);//以(i,j)为起点，深搜.
		}
	}
	int maxlength=-1;
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if(maxlength<a[i][j].length)
				maxlength = a[i][j].length;//找全局的最大滑雪长度 
		}
	}
	
	printf("%d\n",maxlength);
	return 0;
}

