#include<iostream>
#include<iomanip>
using namespace std;
const int shour[32]={0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3,-2,
         -5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9,10,8};
char *zone[32]={"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD","AST","ADT","NST","NDT",
           "EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
const int smin[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,-30,-30,0,0,0,0,0,0,0,0,0,0,0,0,0,30,30,0};
int main()
{
	int n;
	scanf("%d",&n);
        getchar();
	for(int i=0;i<n;i++)
	{
		int k,m;
	    int hour=0,min=0,mhour=0,mmin=0;
	    char A[60],P[60],zone1[10],zone2[10],time[10];
		cin.getline(A,25);
		if(A[0]=='n'||A[0]=='m')
		{
			sscanf(A,"%s %s %s",P,zone1,zone2);
            min=0;
			if(A[0]=='n')
				hour=12;
			else 
				hour=24;
		}else
		{
			sscanf(A,"%d:%d %s %s %s",&hour,&min,time,zone1,zone2);
			if((time[0]=='p'&&hour<12)||(time[0]=='a'&&hour==12))
				hour+=12;
		};
		for(k=0;k<32;k++)
		   if(strcmp(zone1,zone[k])==0)
				break;
		for(m=0;m<32;m++)
            if(strcmp(zone2,zone[m])==0)
			   break;
		mhour=hour+(shour[m]-shour[k]);
		mmin=min+(smin[m]-smin[k]);
		while(mmin>=60)
		{
			mmin=mmin-60;
			mhour=mhour+1;
		}
		while(mmin<0)
		{
			mmin=mmin+60;
			mhour=mhour-1;
		}
		while(mhour<0)
			mhour+=24;
		while(mhour>=24)
			mhour-=24;
		if(mhour==12&&mmin==0)
                    cout<<"noon"<<endl;
		if(mhour==0&&mmin==0)
			cout<<"midnight"<<endl;
		if(mhour>0&&mhour<12)
			cout<<mhour<<":"<<setfill('0')<<setw(2)<<mmin<<' '<<"a.m."<<endl;
		if(mhour==0&&mmin>0)
			cout<<12<<":"<<setfill('0')<<setw(2)<<mmin<<' '<<"a.m."<<endl;
		if((mhour>12&&mhour<24))
			cout<<mhour-12<<":"<<setfill('0')<<setw(2)<<mmin<<' '<<"p.m."<<endl;
		if(mhour==12&&mmin>0)
			cout<<12<<":"<<setfill('0')<<setw(2)<<mmin<<' '<<"p.m."<<endl;
			
	}
        return 0;
}
