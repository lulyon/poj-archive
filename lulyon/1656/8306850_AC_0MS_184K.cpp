#include<iostream>
using namespace std;

int a[110][110];
char str[10];

int main(){
	int t,x,y,length;
	scanf("%d",&t);
	while(t--){
		scanf("%s%d%d%d",str,&x,&y,&length);
		if(str[0]=='B'){
			for(int i=y; i<y+length; ++i){
				for(int j=x; j<x+length; ++j){
					a[i][j]=-1;
				}
			}
		}
		else if(str[0]=='W'){
			for(int i=y; i<y+length; ++i){
				for(int j=x; j<x+length; ++j){
					a[i][j]=1;
				}
			}
		}
		else if(str[0]=='T'){
			int cnt=0;
			for(int i=y; i<y+length; ++i){
				for(int j=x; j<x+length; ++j){
					if(a[i][j]==-1)cnt++;
				}
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}

