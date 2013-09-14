#include<iostream>
using namespace std;

int value[5010][5010];

int main(){
	int num=0;
	for(int i=2; i<=10000; i+=4){
		value[i/2][i/2] = ++num;
		value[i/2+1][i/2-1] = ++num;
		value[i/2+2][i/2] = ++num;
		value[i/2+1][i/2+1] = ++num;
	}
	
	int t;
	scanf("%d",&t);
	int x,y;
	while(t--){
		scanf("%d%d",&x,&y);
		if(x==0 && y==0){
			printf("0\n");
			continue;
		}
		if(value[x][y]){
			printf("%d\n",value[x][y]);
		}
		else{
			printf("No Number\n");
		}
	}
	return 0;
}

