#include<iostream>
#include<algorithm>
using namespace std;

char s[3][3][10];

char mp[3][10] = {
	"even", "up", "down"
};

int real[20];

bool equal(char *a, char *b){
	int lena = strlen(a);
	int lenb = strlen(b);
	
	if(lena!=lenb)return 0;
	for(int i=0; i<lena; ++i){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0; i<3; ++i){
			for(int j=0; j<3; ++j){
				scanf("%s",s[i][j]);
			}
		}
		
		for(int i=0; i<12; ++i){
			real[i] = -1;
		}
		
		int index[3];
		for(int i=0; i<3; ++i){
			for(int k=0; k<3; ++k){
				if(equal(s[i][2],mp[k])){
					index[i] = k;
					break;
				}
			}
		}
		
		for(int i=0; i<3; ++i){
			if(index[i]==0){
				for(int j=0; j<2; ++j){
					for(int k=0; s[i][j][k]; ++k){
						real[s[i][j][k]-'A']=1;
					}
				}
			}
		}
		
		
		
		for(int m=0; m<12; ++m){
			if(real[m]==1)continue;
			
			real[m]=0;
			int lh[3]= {-1,-1,-1};
			for(int i=0; i<3; ++i){
				if(index[i]==0)continue;
				
				int find = 0;
				for(int j=0; j<2; ++j){
					for(int k=0; s[i][j][k];++k){
						if(s[i][j][k]-'A'==m){
							find = 1;
							if(index[i]==1){
								if(j==0)lh[i]=1;
								else lh[i]=0;
							}
							else{
								if(j==0)lh[i]=0;
								else lh[i]=1;
							}
							goto leap;
						}
					}
				}
				leap:;
				if(find==0){
					if(index[i]!=0){
						goto leap2;
					}
				}
				
			}
			//printf("%d %d %d",lh[0],lh[1],lh[2]);
			//system("pause");
			
			sort(lh,lh+3);
			int p;
			for(p=0; p<3; ++p){
				if(lh[p]>=0)break;
			}
			if(p==3)goto leap2;
			for(int pp=p+1;pp<3;++pp){
				if(lh[p]!=lh[pp]){
					goto leap2;
				}
			}
			
			
			if(lh[p]==0){
				printf("%c is the counterfeit coin and it is light.\n",m+'A');
			}
			else{
				printf("%c is the counterfeit coin and it is heavy.\n",m+'A');
			}
			break;
			
			leap2:;
			real[m]=-1;
		}
		
	}
	return 0;
}

