#include<iostream>
#include<math.h>
using namespace std;
char a[20],b[20];
int main()
{
	 while(1)
	 {
		scanf("%s%s",a,b);
		if(a[0]=='0' && b[0]=='0')
			break;
		int alen = strlen(a);
		int blen = strlen(b);
		int i=alen-1;
		int j=blen-1;
		
	//	cout<<a+1<<' '<<b+1<<endl;
	//	system("pause");
		
		int s=0,tmp,cn=0;
		for(;i>=0 && j>=0;i--,j--)
		{
			tmp = a[i]-'0'+b[j]-'0'+s;
			s = tmp/10;
			if(s)cn++;
		}
		if(cn==0)printf("No carry operation.\n");
		else if(cn==1)printf("1 carry operation.\n");
		else printf("%d carry operations.\n",cn);
	 }
    return 0;
}
