#include<iostream>
using namespace std;

char s1[5050],s2[5050];
short dp[5050][5050];

short maxof(short a,short b){
	if(a>b)return a;
	else return b;
}

int main(){
	int len1,len2;
	scanf("%d",&len1);
	scanf("%s",s1);
		len2 = len1;
		
		for(int i=0; i<len1; ++i){
			s2[i] = s1[len1-1-i];
		}
		s2[len2]='\0';
		
		if(s1[0]==s2[0])dp[0][0]=1;
		else dp[0][0]=0;
		
		for(int i=1; i<len2; ++i){
			if(s1[0]==s2[i])dp[0][i]=1;
			else dp[0][i]=dp[0][i-1];
		}
		
		for(int i=1; i<len1; ++i){
			if(s1[i]==s2[0])dp[i][0]=1;
			else dp[i][0]=dp[i-1][0];
		}
		
		for(int i=1; i<len1; ++i){
			for(int j=1; j<len2; ++j){
				
			
				if(s1[i]==s2[j]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{
					dp[i][j]=maxof(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		printf("%d\n",len1-dp[len1-1][len2-1]);
	
	return 0;
}

