#include<iostream>
using namespace std;

int a[26];
int Right[500];

int main(){
	for(int i=0; i<26; ++i){
		a[i] = 0;
	}
	char c;
	while(scanf("%c",&c)!=EOF){
		if(c<='Z' && c>='A')a[c-'A']++;
	}
	
	int max = 0;
	for(int i=0; i<26; ++i){
		if(max<a[i])max=a[i];
	}
	
	for(int i=max; i>=1; --i){
		Right[i]=-1;
		for(int j=0; j<26; ++j){
			if(a[j]>=i){
				Right[i]=j;
			}
		}
	}
	
	for(int i=max; i>=1; --i){
		for(int j=0; j<=Right[i]; ++j){
			if(a[j]>=i){
				printf("*");
			}
			else{
				printf(" ");
			}
			if(j!=Right[i]){
				printf(" ");
			}
			else printf("\n");
		}
		
	}
	for(int i=0; i<26; ++i){
		printf("%c", i+'A');
		if(i!=25)printf(" ");
		else printf("\n");
	}
	return 0;
}

