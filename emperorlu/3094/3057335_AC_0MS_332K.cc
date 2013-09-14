#include<iostream>
using namespace std;
char a[300];
int main()
{
	long sum;
	while(1)
	{
		gets(a);
		if(a[0]=='#')break;
		sum=0;
		for(int i=0;a[i];i++)
			if(a[i]!=' ')
				sum+=(a[i]-'A'+1)*(i+1);
		cout<<sum<<endl;
	}
	return 0;
}
