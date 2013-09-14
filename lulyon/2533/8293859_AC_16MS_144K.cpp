#include<iostream>
using namespace std;

const int maxn = 1010;
int a[maxn];
int length[maxn];

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0; i<n; ++i){
		scanf("%d",&a[i]);
	}
	length[0]=1;
	for(int i=1; i<n; ++i){
		int maxlen=0;
		for(int j=0; j<i; ++j){
			if(a[j]<a[i] && maxlen<length[j]){
				maxlen = length[j];
			}
		}
		length[i] = maxlen+1;
	}
	int maxlength=-1;
	for(int i=0; i<n; ++i){
		if(maxlength<length[i]){
			maxlength = length[i];
		}
	}
	printf("%d\n",maxlength);
	return 0;
}

