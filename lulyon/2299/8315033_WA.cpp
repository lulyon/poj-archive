#include<iostream>
using namespace std;

int a[500010];
int tmp[500010];
int cnt;

void merge(int *p, int *mid, int *q){
	int *index = tmp;
	int *pindex = p;
	int *qindex = mid+1;
	for(; pindex<=mid && qindex<=q; ){
		if(*pindex<=*qindex){
			*index = *pindex;
			pindex++;
			++index;
		}
		else{
			*index = *qindex;
			qindex++;
			++index;
			cnt+=mid-pindex+1;
		}
	}
	
	for(;pindex<=mid;){
		*index = *pindex;
		pindex++;
		++index;
		
	}
	
	for(;qindex<=q;){
		*index = *qindex;
		qindex++;
		++index;
		//cnt++;
	}
	
	index = tmp;
	for(int *i=p; i<=q; ){
		*i = *index;
		i++;
		index++;
	}
}

void merge_sort(int *p, int *q){
	if(p<q){
		int *mid = p+(q-p)/2;
		merge_sort(p, mid);
		merge_sort(mid+1, q);
		merge(p,mid,q);
	}
}

int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		for(int i=0; i<n; ++i){
			scanf("%d",&a[i]);
		}
		cnt=0;
		merge_sort(a,a+n-1);
		printf("%d\n",cnt);
	}
	return 0;
}

