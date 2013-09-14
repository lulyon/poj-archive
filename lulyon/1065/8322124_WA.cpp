#include<iostream>
#include<algorithm>
using namespace std;

typedef struct INFO{
	int x,y;
}info;

info a[5050];

bool visited[5050];

int cmp(const info &s, const info &t){
	if(s.x!=t.x)return s.x<t.x;
	else return s.y>t.y;
}

int main(){
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0; i<n; ++i){
			scanf("%d%d",&a[i].x, &a[i].y);
			visited[i]=0;
		}
		sort(a, a+n, cmp);
		int cnt=0;
		for(int i=0; i<n; ++i){
			if(visited[i]==0){
				cnt++;
				visited[i]=1;
				int xmax,ymax;
				xmax = a[i].x;
				ymax = a[i].y;
				
				for(int j=i+1; j<n; ++j){
					if(visited[j]==0 &&xmax<=a[j].x && ymax<=a[j].y){
						xmax = a[j].x;
						ymax = a[j].y;
						visited[j]=1;
					}
				}
			}	
		}
		printf("%d\n",cnt);
	}
	return 0;
}

