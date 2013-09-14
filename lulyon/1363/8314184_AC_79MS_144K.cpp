#include<iostream>
using namespace std;
int stack[1010];
int a[1010];
int main(){
	int n;
	while(1){
		leap:;
		scanf("%d",&n);
		if(n==0)break;
		
		while(1){
			scanf("%d",&a[1]);
			if(a[1]==0){
				printf("\n");
				goto leap;
			}
			for(int i=2; i<=n; ++i){
				scanf("%d",&a[i]);
			}
		
			int top=0;
			int pos=1;
			bool yes=1;
			for(int i=1; i<=n; ++i){
				if(pos<=a[i]){
					for(int j=pos;j<=a[i]; ++j){
						stack[top++]=j;
					}
					pos = a[i]+1;
				}
				if(stack[--top]!=a[i]){
					yes=0;
					break;
				}
			}
			if(yes)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

