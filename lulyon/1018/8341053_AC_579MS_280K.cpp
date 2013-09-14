#include<iostream>
#include<algorithm>
using namespace std;

typedef struct INFO{
	int num;
	int bandwidth[110],price[110];
}infoType;

infoType info[110];

typedef struct STACK{
	int bandwidth[110*110];
	int top;
}StackType;

StackType stack;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int top=0;
		stack.top=0;
		for(int i=0; i<n; ++i){
			scanf("%d", &info[i].num);
			for(int j=0; j<info[i].num; ++j){
				scanf("%d%d", &info[i].bandwidth[j], &info[i].price[j]);
				stack.bandwidth[stack.top++] = info[i].bandwidth[j];
			}
		}
		sort(stack.bandwidth, stack.bandwidth+stack.top);
		double maxbp = 0;
		for(int i=0; i<stack.top; ++i){
			int sum = 0;
			for(int j=0; j<n; ++j){
				bool flag = 0;
				int minprice = 1000000;
				for(int k=0; k<info[j].num; ++k){
					if(stack.bandwidth[i]<=info[j].bandwidth[k] && minprice>info[j].price[k]){
						minprice = info[j].price[k];
						flag = 1;
					}
				}
				if(flag){
					sum += minprice;
				}
				else{
					sum = 1000000;
					break;
				}
			}
			double tmp = stack.bandwidth[i]/(double)sum;
			if(maxbp<tmp){
				maxbp = tmp;
			}
		}
		printf("%.3lf\n",maxbp);
	}
	return 0;
}

