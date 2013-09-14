#include<iostream>
using namespace std;

double a[3][3] = {4.5, 150, 200, 6.0, 300, 500, 5.0, 200, 300};
char str[3][20] = {"Wide Receiver", "Lineman", "Quarterback"};

int main(){
	double s[3];
	while(1){
		scanf("%lf%lf%lf",s,s+1,s+2);
		if(s[0]==0 && s[1]==0 && s[2]==0)break;
		
		int cnt=0;
		bool no=1;
		for(int i=0; i<3; ++i){
			if(s[0]<=a[i][0] && s[1]>=a[i][1] && s[2]>=a[i][2]){
				if(cnt==0){
					printf("%s", str[i]);
				}
				else{
					printf(" %s", str[i]);
				}
				no=0;
				cnt++;
			}
		}
		if(no)printf("No positions");
		printf("\n");
	}
	return 0;
}

