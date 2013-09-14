#include <iostream>

const int maxn = 1000010;

int a[maxn];

int left[maxn];

int right[maxn];

int main(int argc, char ** argv){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;

		for(int i=1; i<=n; ++i){
			scanf("%d",&a[i]);
		}

		left[1] = a[1];
		for(int i=2; i<=n; ++i){
			if(left[i-1]>0)left[i] = a[i] + left[i-1];
			else left[i] = a[i];
		}

		for(int i=2; i<=n; ++i){
			if(left[i]<left[i-1])left[i] = left[i-1];
		}

		right[n] = a[n];
		for(int i=n-1; i>=1; --i){
			if(right[i+1]>0)right[i] = a[i] + right[i+1];
			else right[i] = a[i];
		}

		for(int i=n-1; i>=1; --i){
			if(right[i]<right[i+1])right[i] = right[i+1];
		}

		int max = -INT_MAX;
		for(int i=1; i<n; ++i){
			if(max<left[i]+right[i+1]){
				max = left[i]+right[i+1];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}

