#include<iostream>
using namespace std;

char s[100010], t[100010];

bool sub(char *a, char *b){
	int lena = strlen(a);
	int lenb = strlen(b);
	
	if(lena>lenb)return 0;
	
	int pos=-1;
	for(int i=0; i<lena; ++i){
		int findone=0;
		for(int j=pos+1; j<lenb; ++j){
			if(a[i]==b[j]){
				pos = j;
				findone=1;
				break;
			}
		}
		if(findone==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	while(scanf("%s%s",s,t)!=EOF){
		
		if(sub(s,t))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

