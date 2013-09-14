#include<iostream>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int x,y;
	while(t--){
		scanf("%d%d",&x,&y);
		if(x>=y)printf("MMM BRAINS\n");
		else printf("NO BRAINS\n");
	}
	return 0;
}

