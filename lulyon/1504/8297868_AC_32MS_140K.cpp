#include<iostream>
using namespace std;

void Add(int *a, int lena, int *b, int lenb, int *c, int &lenc){
	int s=0;
	c[0]=0;
	lenc=1;
	int i=0;
	for(; i<lena && i<lenb; ++i){
		c[i] = (a[i]+b[i]+s)%10;
		s = (a[i]+b[i]+s)/10;
	}
	
	for(; i<lena; ++i){
		c[i] = (a[i]+s)%10;
		s = (a[i]+s)/10;
	}
	
	for(; i<lenb; ++i){
		c[i] = (b[i]+s)%10;
		s = (b[i]+s)/10;
	}
	
	if(s>0){
		c[i] = s;
		lenc = i+1;
	}
	else{
		lenc = i;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	char s1[110],s2[110];
	int a[110],b[110], c[110];
	int lena, lenb, lenc;
	while(t--){
		scanf("%s%s",s1,s2);
		lena = strlen(s1);
		for(int i=0; i<lena; ++i){
			a[i] = s1[i]-'0';
		}
		lenb = strlen(s2);
		for(int i=0; i<lenb; ++i){
			b[i] = s2[i]-'0';
		}
		
		Add(a,lena, b, lenb, c, lenc);
		int begin=-1;
		for(int i=0; i<lenc; ++i){
			if(c[i]!=0){
				begin=i;
				break;
			}
		}
		for(int i=begin; i<lenc; ++i){
			printf("%d",c[i]);
		}
		printf("\n");
	}
	return 0;
}

