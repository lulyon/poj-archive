#include<iostream>
using namespace std;
const int maxn=10000000;
int cnt[maxn];
char str[100];
int mapping[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int main(){
	for(int i=0;i<maxn;++i){
		cnt[i]=0;
	}
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
		scanf("%s",str);
		
		int exp=1000000,index=0;
		for(int j=0;str[j]!='\0';++j){
			if(str[j]=='-')continue;
			
			if(str[j]<='9' &&str[j]>='0'){
				index += exp*(str[j]-'0');
				exp /= 10;
			}
			
			if(str[j]<='Z'&&str[j]>='A'){
				index += mapping[str[j]-'A']*exp;
				exp /= 10;
			}
		}
		cnt[index]++;
	}
	
	bool flag=0;
	for(int i=0;i<maxn;++i){
		if(cnt[i]>1){
			flag=1;
			printf("%d-%d %d\n",i/10000,i%10000,cnt[i]);
		}
	}
	
	if(flag==0)printf("No duplicates.\n");
	return 0;
}

