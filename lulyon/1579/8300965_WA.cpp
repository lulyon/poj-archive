#include<iostream>
using namespace std;

int a[25][25][25];

int main(){
	for(int i=1; i<=20; ++i){
		for(int j=1; j<=20; ++j){
			for(int k=1; k<=20; ++k){
				int sum=0;
				if(i<j && j<k){
					if(k==1)sum++;
					else	sum+=a[i][j][k-1];
					
					if(j==1||k==1)sum++;
					else	sum+=a[i][j-1][k-1];
					
					if(j==1)sum--;
					else	sum-=a[i][j-1][k];
					
					a[i][j][k]=sum;
				}
				else{
					if(i==1)sum++;
					else	sum+=a[i-1][j][k];
					
					if(i==1 || j==1)sum++;
					else	sum+=a[i-1][j-1][k];
					
					if(i==1 || k==1)sum++;
					else	sum+=a[i-1][j][k-1];
					
					if(i==1 || j==1 || k==1)sum--;
					else	sum-=a[i-1][j-1][k-1];
					
					a[i][j][k]=sum;
				}
			}
		}
	}
	
	int aa,b,c;
	while(1){
		scanf("%d%d%d",&aa,&b,&c);
		if(aa==-1&&b==-1&&c==-1){
			break;
		}
		if(aa<=0 || b<=0 || c<=0){
			printf("1\n");
		}
		else if(aa>20 || b>20 || c>20){
			printf("%d\n",a[20][20][20]);
		}
		else{
			printf("%d\n",a[aa][b][c]);
		}
	}
	return 0;
}

