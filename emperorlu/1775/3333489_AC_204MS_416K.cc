#include<iostream>
using namespace std;
long a[10]={362880,40320,5040,720,120,24,6,2,1,1};
int main()
{
	
	int in;
	while(1)
	{
		cin>>in;
		if(in<0)break;
		if(in==0)cout<<"NO"<<endl;
		else 
		{
			for(int i=0;i<10;i++)
				if(in>=a[i])in-=a[i];
			if(in==0)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		} 				
	}
	return 0;	
}
