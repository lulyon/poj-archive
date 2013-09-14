#include<iostream>
#include<algorithm>
using namespace std;
char str[110][110];
struct Type{
	int index;
	int order;
}data[110];

int cmp(const struct Type &a, const struct Type &b){
	if(a.order<b.order)return 1;
	else if(a.order==b.order){
		if(a.index<b.index)return 1;
		else return 0;
	}
	else return 0;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%s",str[i]);
		data[i].index=i;
		data[i].order=0;
		
		for(int j=0;j<n;++j){
			for(int k=j+1;k<n;++k){
				if(str[i][j]>str[i][k])
					data[i].order++;
			}
		}
	}
	sort(data,data+m,cmp);
	
	for(int i=0;i<m;++i){
		printf("%s\n",str[data[i].index]);
	}
	return 0;
}

