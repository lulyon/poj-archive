#include<iostream>
#include<map>
using namespace std;
string a; 
int main()
{
	while(1)
	{
		cin>>a;
		if(a[0]=='*')
			break;
		int len = a.size();
		if(len == 1)
		{
			cout<<a<<" is surprising."<<endl;
			continue;
		}
		map<string,int> str;
		string tmp;
		int i,j,k;
		for(i=0;i<=len-2;i++)
		{
			for(j=0,k=i+j+1;k<len;j++,k++)
			{
				tmp.clear();
				tmp.push_back(a[j]);
				tmp.push_back(a[k]);
				if(str[tmp]++)
					break;
			}
			if(k<len)break;
		}
		if(i<=len-2)
			cout<<a<<" is NOT surprising."<<endl;
		else
			cout<<a<<" is surprising."<<endl;
	}
	return 0;
}
