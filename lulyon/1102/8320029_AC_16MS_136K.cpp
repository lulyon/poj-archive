#include<iostream>
using namespace std;

char mp[10][20] = {" - | |   | | - ", "     |     |   ", " -   | - |   - ", " -   | -   | - ", "   | | -   |   ", " - |   -   | - ", " - |   - | | - ", " -   |     |   ", " - | | - | | - ", " - | | -   | - "};
char str[100];

int main(){
	int n;
	while(1){
		scanf("%d%s",&n,str);
		if(n==0)break;
		
		int length = strlen(str),index;
		for(int k=0; k<5; ++k){
			if(k%2==0){
				for(int i=0; i<length; ++i){
					index = str[i] -'0';
					printf("%c",mp[index][3*k]);
					for(int j=0; j<n; ++j){
						printf("%c",mp[index][3*k+1]);
					}
					printf("%c",mp[index][3*k+2]);
					if(i==length-1)printf("\n");
					else printf(" ");
				}
			}
			else{
				for(int j=0; j<n; ++j){
					for(int i=0; i<length; ++i){
						index = str[i] -'0';
						printf("%c",mp[index][3*k]);
						for(int jj=0; jj<n; ++jj){
							printf("%c",mp[index][3*k+1]);
						}
						printf("%c",mp[index][3*k+2]);
						if(i==length-1)printf("\n");
						else printf(" ");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}

