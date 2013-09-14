#include<iostream>
using namespace std;

int a[110][110];
int f[110][110][110];

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0; i<n;++i){
		for(int j=0; j<n; ++j){
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=0; i<n; ++i){
		for(int k=0; k<n; ++k){
			f[i][i][k] = a[i][k];
		}
	}
	
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n;++j){
			for(int k=0; k<n; ++k){
				f[i][j][k] = f[i][j-1][k] + a[j][k];
			}
		}
	}
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=1; k<n; ++k){
				if(f[i][j][k-1]>0)f[i][j][k] += f[i][j][k-1];
			}
		}
	}
	
	int maxsum = -200;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			for(int k=0; k<n; ++k){
				if(f[i][j][k]>maxsum)maxsum = f[i][j][k];
			}
		}
	}
	
	printf("%d\n",maxsum);
	return 0;
}

