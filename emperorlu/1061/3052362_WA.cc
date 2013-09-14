#include "iostream"
using namespace std;


int  main()
{
	long int x,y,m,n,l,i;
	cin>>x>>y>>m>>n>>l;
	long int k,j=0;
	if((m-n)%l==0)
    {
        if((x-y)%l!=0)
	       cout<<"Impossible"<<endl;
        else cout<<"0"<<endl;
    }
    else if(m>n)
    {
		k=y-x;
		if(k<0&&(-k)%(m-n)==0&&l%(m-n))
            cout<<l-(-k)/(m-n);
        else
        {
		    for(i=0;i<m-n;i++)
            {

			    if(k>0)
                {
                    j+=k/(m-n);
                    k=k%(m-n);
                }
			    if(k==0)
                {
				    cout<<j<<endl;
				    break;
			    }
			    k=(l+k);
		    }
		    if(i==m-n)
            cout<<"Impossible"<<endl;
        }
	}
	else if(m<n)
    {
		k=x-y;
		if(k<0&&(-k)%(n-m)==0&&l%(n-m))
            cout<<l-(-k)/(n-m);
        else
		{
		    for(i=0;i<n-m;i++)
            {
			    if(k>0)
                {
                    j+=k/(n-m);
                    k=k%(n-m);
                }
			    if(k==0)
                {
				    cout<<j<<endl;
				    break;
			    }
			    k=(l+k);
		    }
		    if(i==n-m)
            cout<<"Impossible"<<endl;
        }
	}
	//while(1);
	return 0;
}
