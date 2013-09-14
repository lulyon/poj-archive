#include<iostream>
using namespace std;

int a[110];

char stack[1010];

int main(){
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; ++i){
			scanf("%d",&a[i]);
		}
		int top=-1;
		for(int k=0; k<a[1]; ++k){
			stack[++top] = '(';
		}
		stack[++top]=')';
		for(int i=2; i<=n; ++i){
			for(int k=0; k<a[i]-a[i-1]; ++k){
				stack[++top] = '(';
			}
			stack[++top]=')';
		}
		int index[110],num=0;
		for(int i=0; i<=top; ++i){
			if(stack[i]==')'){
				index[++num]=i;
			}
		}
		for(int i=1;i<=num; ++i){
			int sum=1;
			for(int j=index[i]-1;j>=0; --j){
				if(stack[j]==')'){
					sum++;
				}
				else if(stack[j]=='('){
					sum--;
				}
				if(sum==0){
					int cnt=0;
					for(int k=j+1; k<=index[i]; ++k){
						if(stack[k]==')')cnt++;
					}
					printf("%d",cnt);
					if(i==num)printf("\n");
					else printf(" ");
					break;
				}
			}
		}
	}
	return 0;
}

