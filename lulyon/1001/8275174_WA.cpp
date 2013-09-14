#include<iostream>
using namespace std;

int tmp[1000000];
int lentmp;

int tmp2[1000000];
int lentmp2;

int tmp3[1000000];
int lentmp3;

char result[1000000];
int lenr;


void Add(int *a, int lena, int *b, int lenb, int *c, int &lenc){
	int i,s=0;
	for(i=0;i<lena&&i<lenb;++i){
		c[i] = (a[i]+b[i]+s)%10;
		s = (a[i]+b[i]+s)/10;
	}
	for(;i<lena;++i){
		c[i] = (a[i]+s)%10;
		s = (a[i]+s)/10;
	}
	for(;i<lenb;++i){
		c[i] = (b[i]+s)%10;
		s = (b[i]+s)/10;
	}
	if(s==0)lenc = i;
	else{
		c[i] = s;
		lenc = i+1;
	}
}


void Mul(int *a,int lena,int *b,int lenb, int *c, int &lenc){
	lenc = 1;
	c[0] = 0;
	
	for(int i=0;i<lenb;++i){
		
		for(int k=0;k<i;++k){
			tmp[k]=0;
		}
		int s=0;
		int j;
		for(j=0;j<lena;++j){
			tmp[i+j] = (a[j]*b[i]+s)%10;
			s = (a[j]*b[i]+s)/10;
		}
		if(s==0)lentmp = i+j;
		else{
			tmp[i+j]=s;
			lentmp = i+j+1;
		}
		
	/*	
		for(int k=lentmp-1; k>=0; --k){
			printf("%d",tmp[k]);
		}
		system("pause");
		
		for(int k=lenc-1; k>=0; --k){
			printf("%d",c[k]);
		}
		system("pause");
	*/
		Add(c,lenc, tmp, lentmp, tmp2, lentmp2);
		
		for(int k=0; k<lentmp2; ++k){
			c[k] = tmp2[k];
		}
		lenc = lentmp2;
	
	/*	
		for(int k=lenc-1; k>=0; --k){
			printf("%d",c[k]);
		}
		system("pause");
		
		
	*/	
	
	}
}



int main(){
	
	
	int lena,lenc;
	int a[10];
	int c[100000];
	lena = 5;

	
	char str[10];
	int n,exp;
	while(scanf("%s%d",str,&n)!=EOF){
		
		/*
		if(str[1]=='.'){
			exp = 4;
			a[0]=str[5]-'0';
			a[1]=str[4]-'0';
			a[2]=str[3]-'0';
			a[3]=str[2]-'0';
			a[4]=str[0]-'0';
		}
		else if(str[2]=='.'){
			exp = 3;
			a[0]=str[5]-'0';
			a[1]=str[4]-'0';
			a[2]=str[3]-'0';
			a[3]=str[1]-'0';
			a[4]=str[0]-'0';
		}
		*/
		int point;
		for(int i=0;i<6;++i){
			if(str[i]=='.'){
				point = i;
				exp = 5-point;
				break;
			}
		}
		
		for(int i=0, j=5; i<5; ){
			if(j==point){
				--j;
				continue;
			}
			a[i]=str[j]-'0';
			++i;--j;
		}
		
		
		
	/*	
		printf("%s",str);
		system("pause");
		
		for(int i=0; i<5; ++i){
			printf("%d",a[i]);
		}
		system("pause");
	*/	
		
		for(int k=0; k<lena; ++k){
			c[k] = a[k];
		}
		lenc = lena;
		
		for(int i=1;i<n;++i){
			Mul(c,lenc,a,lena,tmp3,lentmp3);
			for(int k=0; k<lentmp3; ++k){
				c[k] = tmp3[k];
			}
			lenc = lentmp3;
		}
		
		lenr = 0;
		if(lenc == exp*n){
			result[lenr++] = '.';
		}
		for(int i=lenc-1; i>=0; --i){
			result[lenr++] = c[i]+'0';
			if(i == exp*n){
				result[lenr++] = '.';
			}
		}
		
		/*
		for(int i=0; i<lenr; ++i){
			printf("%c",result[i]);
		}
		
		system("pause");
		*/
		
		
		int begin,end;
		begin=0;
		for(int i=0;i<lenr;++i){
			if(result[i]!='0'){
				begin=i;
				break;
			}
		}
		
		end=0;
		for(int i=lenr-1;i>=0;--i){
			if(result[i]!='0'){
				end=i;
				break;
			}
		}
		
		for(int i=begin; i<=end;++i){
			printf("%c",result[i]);
		}
		printf("\n");
	}
	
	//system("pause");
	return 0;
}

