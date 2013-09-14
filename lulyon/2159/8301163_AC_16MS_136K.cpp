#include<iostream>
#include<algorithm>
using namespace std;
char s1[110],s2[110];
int n1[30],n2[30];

int main(){
	scanf("%s%s",s1,s2);
	int len1,len2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	if(len1!=len2){
		printf("NO\n");
	}
	else{
		for(int i=0; i<26; ++i){
			n1[i] = n2[i] = 0;
		}
		for(int i=0; i<len1; ++i){
			n1[s1[i]-'A']++;
		}
		for(int i=0; i<len2; ++i){
			n2[s2[i]-'A']++;
		}
		sort(n1, n1+26);
		sort(n2, n2+26);
		
		bool yes=1;
		for(int i=0; i<26; ++i){
			if(n1[i]!=n2[i]){
				printf("NO\n");
				yes=0;
				break;
			}
		}
		if(yes)printf("YES\n");
	}
	//system("pause");
	return 0;
}

