#include<iostream>

int tmp[1000000];
int lentmp;

int tmp2[1000000];
int lentmp2;

int tmp3[1000000];
int lentmp3;

int num1[100];
int len1;

int num2[100];
int len2;

char str[100];

int result[1000000];
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

		Add(c,lenc, tmp, lentmp, tmp2, lentmp2);
		
		for(int k=0; k<lentmp2; ++k){
			c[k] = tmp2[k];
		}
		lenc = lentmp2;
	}
}


bool compare(int *a, int *b, int len){
	for(int pos = 0; pos<len; ++pos){
		bool flag = 1;
		for(int i=0, j=pos; i<len; ++i, j=(j+1)%len){
			if(a[i] != b[j]){
				flag = 0;
				break;
			}
		}
		if(flag == 1)return 1;
	}
	return 0;
}

int main()
{
	while(scanf("%s",str)!=EOF){
		len1 = strlen(str);
		for(int i = len1-1, j=0; j<len1; i--, j++){
			num1[j] = str[i]-'0';
		}

		bool flag = 0;
		for(int i=1; i<=len1; ++i){
			if(i<10){
				num2[0] = i;
				len2 = 1;
			}
			else{
				num2[0] = i%10;
				num2[1] = i/10;
				len2 = 2;
			}

			Mul(num1, len1, num2, len2, result, lenr);

			int pos = -1;
			for(int j=lenr-1; j>=0; j--){
				if(result[j]!=0){
					pos = j;
					break;
				}
			}

			if(pos>=len1){
				for(int j = len1-1; j>=0; j--){
					printf("%d", num1[j]);
				}
				printf(" is not cyclic\n");
				flag = 1;
				break;
			}
			for(int j=pos+1; j<=len1; ++j){
				result[j] = 0;
			}
			if(compare(num1, result, len1)==0){
				for(int j = len1-1; j>=0; j--){
					printf("%d", num1[j]);
				}
				printf(" is not cyclic\n");
				flag = 1;
				break;
			}
		}

		if(flag == 0){
			for(int j = len1-1; j>=0; j--){
				printf("%d", num1[j]);
			}
			printf(" is cyclic\n");
		}

	}
	return 0;
}
