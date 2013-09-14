#include<iostream>
using namespace std;
int main()
{
    int n,m;
    char a[210];
    while(1)
    {
		cin>>n;
		if(!n)break;
		cin>>a;
		int len=strlen(a);
		m=len/n;
		int tmp;
		for(int i=1;i<m;i+=2)
			for(int j=i*n,k=j+n-1;j<k;j++,k--)
			{
				tmp=a[j];
				a[j]=a[k];
				a[k]=tmp;
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cout<<a[i+j*n];
		cout<<endl;		
    }
    return 0;
}
