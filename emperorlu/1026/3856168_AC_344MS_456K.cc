#include<iostream>
#include<string>
using namespace std;

int  main()
{
	typedef basic_string<char>cString;
	typedef basic_string<int>nString;
	int n,k,h,count,a;
    
    
	cin>>n;
	nString nS1(200,1);
	for(int i=0;i<n;i++)
		cin>>nS1[i];
	while(1)
	{
		cin>>k;
		if(k==0)
		{
                    cout<<endl;
			cin>>n;
			if(n==0) break;
			for(int i=0;i<n;i++)
				cin>>nS1[i];
			cin>>k;
		}
		nString nS2(n,0),nS3(n,0);
		cString cS1(n,' '),cS2(n,' ');
		cin.get();
		getline(cin,cS1);
		for(int i=cS1.size();i<n;i++)
			cS1+=' ';
		for(int i=1;i<=n;i++)
		{
			if(nS2[i-1]==0)
			{
				nS3[0]=i;
				count=1;
				for(h=i;h<=n;h++)
				{
					nS3[count]=nS1[nS3[count-1]-1];
					nS2[nS3[count-1]-1]=1;
					if(nS1[nS3[count-1]-1]==i)break;
					count++;
				}
				a=k%count;
				for(h=0;h<count;h++)
				{
					if(h>=count-a)a-=count;
					cS2[nS3[h+a]-1]=cS1[nS3[h]-1];
				}
			}
		}
		cout<<cS2<<endl;
	}
    
    
        return 0;
}
