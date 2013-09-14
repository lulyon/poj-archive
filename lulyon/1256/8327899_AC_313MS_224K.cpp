#include<iostream>
#include<algorithm>
using namespace std;

char str[20];
int mp[20];

int stack[20];
int top;

bool visited[20];

void pailie(int *a, int n){
	if(top==n){
		for(int i=1; i<=n; ++i){
			if(stack[i]%2==1){
				printf("%c", 'a'+(stack[i]-1)/2);
			}
			else{
				printf("%c", 'A'+stack[i]/2);
			}
		}
		printf("\n");
		return;
	}
	
	for(int i=1; i<=n; ++i){
		if(visited[i]==0){
			if(i==1){
				visited[i]=1;
				stack[++top]=a[i];
				pailie(a,n);
				--top;
				visited[i]=0;
			}
			else{
				if(a[i]!=a[i-1]){
					visited[i]=1;
					stack[++top]=a[i];
					pailie(a,n);
					--top;
					visited[i]=0;
				}
				else{
					if(visited[i-1]==1){
						visited[i]=1;
						stack[++top]=a[i];
						pailie(a,n);
						--top;
						visited[i]=0;
					}
				}
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		scanf("%s",&str[1]);
		
		int n=0;
		for(int i=1; str[i]; ++i){
			if(str[i]<='Z' && str[i]>='A'){
				mp[++n] = (str[i]-'A')*2;
			}
			else if(str[i]>='a' && str[i]<='z'){
				mp[++n] = (str[i]-'a')*2+1;
			}
		}
		sort(mp+1, mp+n+1);
		
		top=0;
		for(int i=1; i<=n; ++i){
			visited[i]=0;
		}
		pailie(mp,n);
	}
	return 0;
}

