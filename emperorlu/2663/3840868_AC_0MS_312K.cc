#include <stdio.h>
long tri(int n)
{
	if(n==1)return 3;
	if(n==2)return 11;
	long sum,i,temp;
	sum=1;
	temp=3;
	for(i=1;i<n;i++){
		sum=sum+temp;
		temp=3*temp+2*(sum-temp);
	}
	return temp;
}
int main()
{
	int input;
	scanf("%d",&input);
	while(input!=-1){
		if(input==0)printf("1\n");
                else if(input%2)printf("0\n");
		else printf("%ld\n",tri(input/2));
		scanf("%d",&input);
	}
}