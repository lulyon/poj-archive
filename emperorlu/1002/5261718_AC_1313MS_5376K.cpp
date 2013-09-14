#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(const string &astr,const string &bstr)
{
	for (int i=0;i<8;++i)
	{
		if(astr.at(i)<bstr.at(i))return 1;
		else if(astr.at(i)>bstr.at(i))return 0;
	}
	return 0;
}
bool isequal(const string &astr,const string &bstr)
{
	for (int i=0;i<8;++i)
	{
		if(astr.at(i)!=bstr.at(i))return 0;
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	vector<string> strList;
	string str1,str2;

	int mapping[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

	for (int i=0;i<n;++i)
	{
		cin>>str1;
		int strSize = str1.size();
		for (int j=0;j<strSize;++j)
		{
			if(str1.at(j)>='A'&&str1.at(j)<='Z')
			{
				str2.push_back(mapping[str1.at(j)-'A']+'0');
				if(str2.size()==3)str2.push_back('-');
			}
			else if(str1.at(j)>='0'&&str1.at(j)<='9')
			{
				str2.push_back(str1.at(j));
				if(str2.size()==3)str2.push_back('-');
			}
		}
		strList.push_back(str2);
		str1.clear();
		str2.clear();
	}
	sort(strList.begin(),strList.end(),cmp);
	int listSize = strList.size();
	int cnt=1;
	bool flag=0;
	for (int i=0;i<listSize-1;++i)
	{
		if(isequal(strList.at(i),strList.at(i+1)))cnt++;
		else
		{
			if(cnt>1)
			{
				cout<<strList.at(i)<<' '<<cnt<<endl;
				flag=1;
			}
			cnt=1;
		}
	}
	if(cnt>1)
	{
		cout<<strList.at(listSize-1)<<' '<<cnt<<endl;
		flag=1;
	}
	if(!flag)cout<<"No duplicates."<<endl;
	return 0;
}
