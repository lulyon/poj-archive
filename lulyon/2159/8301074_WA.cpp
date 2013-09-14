#include<iostream>
#include<algorithm>
using namespace std;
char s1[110],s2[110];

bool str_equal(char *s1, char *s2, int len1, int len2){
	if(len1!=len2)return 0;
	for(int i=0; i<len1; ++i){
		if(s1[i]!=s2[i])return 0;
	}
	return 1;
}

int main(){
	scanf("%s%s",s1,s2);
	int len1,len2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	if(len1!=len2){
		printf("NO\n");
	}
	else{
		for(int i=0; i<len2; ++i){
			if(s2[i]=='Z')s2[i]='A';
			else s2[i]++;
		}
		sort(s1,s1+len1);
		sort(s2,s2+len2);
		
		if(str_equal(s1,s2,len1,len2)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	
	return 0;
}

