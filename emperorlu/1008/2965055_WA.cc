#include<stdio.h>
#include<string.h>
const char hmonth[20][10]=
{"pop","no","zip",
"zotz","tzec","xul",
"yoxkin","mol","chen",
"yax","zac","ceh",
"mac","kankin","muan",
"pax","koyab","cumhu","uayet"};
const char tday[25][10]=
{"imix","ik","akbal",
"kan","chicchan","cimi",
"manik","lamat","muluk",
"ok","chuen","eb","ben",
"ix","mem","cib","caban",
"eznab","canac","ahau"};
int main()
{
	int t;
	int hd,hm,hy,sum;
	int td,tm,ty;
	scanf("%d",&t);
	char m[10];
	int cs=t;
	printf("%d\n",cs);
	while(t--)
	{
		scanf("%d. %s%d",&hd,m,&hy);
		int i;
		for(i=0;i<19;i++)
		{
			if(strcmp(m,hmonth[i])==0)
				break;
		}
		sum=365*hy+20*i+hd+1;
		ty=sum/260;
		//sum%=260;
		if(sum%260==0)ty--;
		tm=sum%13;
	//	if(tm==0)tm=13;
		td=sum%20-1;
	//	if(td==-1)td=19;
		//printf("%d\n",cs);
		printf("%d %s %d\n",tm,tday[td],ty);
	}
	return 0;
}

