#include<iostream>
using namespace std;
const int maxv = 500;
const int maxp = 50;
int x[maxv];
int d[maxv][maxv];
int f[maxv][maxp];

int main()
{
	int v, p;
	scanf("%d%d",&v, &p);
	for(int i=1; i<=v; ++i){
		scanf("%d", &x[i]);
	}

	for(int i=1; i<=v; ++i){
		for(int j=i; j<=v; ++j){
			int sum = 0;
			for(int k=i; k<=j; ++k){
				sum += min(x[k]-x[i], x[j]-x[k]);
			}
			d[i][j] = sum;
		}
	}

	f[1][1]=0;
	for(int ip=1; ip<=1; ++ip){
		for(int jv=2; jv<=v; ++jv){
			f[jv][ip] = 0;
			for(int k=1; k<=jv; ++k){
				f[jv][ip] += x[jv]-x[k];
			}
		}
	}
	for(int ip=2; ip<=p; ++ip){
		for(int jv=1; jv<=v; ++jv){
			if(jv<=ip){
				f[jv][ip] = 0;
			}
			else{
				int min = INT_MAX;
				for(int w=1; w<jv; ++w){
					int tmp = f[w][ip-1] + d[w][jv];
					if(tmp<min)min=tmp;
				}
				f[jv][ip] = min;
			}
		}
	}

	int min = INT_MAX;
	for(int iv=1; iv<=v; ++iv){
		int sum = 0;
		for(int w=iv; w<=v; ++w){
			sum += x[w] - x[iv];
		}
		if(sum + f[iv][p]<min){
			min = sum + f[iv][p];
		}
	}
	printf("%d\n", min);

	return 0;
}

