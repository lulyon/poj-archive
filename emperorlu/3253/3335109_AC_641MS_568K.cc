#include<iostream>
using namespace std;
__int64 pieces[200000];
int compare(const void *ele1,const void * ele2)
{
	return (*(__int64*)ele1)-(*(__int64*)ele2);
}
int main()
{
	int i,j,num;
	cin>>num;
	for(i=0;i<num;i++)
	{
		cin>>pieces[i];
	}
	qsort((void*)pieces,num,sizeof(pieces[0]),compare);
	__int64 cost=0;
	__int64 temp;
	for(i=1;i<num;i++)
	{
		pieces[i]=pieces[i]+pieces[i-1];
		cost+=pieces[i];

		temp=pieces[i];
		for(j=i+1;j<num;j++)
		{
			if(temp>pieces[j])
			{
				pieces[j-1]=pieces[j];
			}
			else {break;}
		}
		pieces[j-1]=temp;
	}
	cout<<cost<<endl;
	return 0;
}
