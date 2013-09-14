#include<iostream>
#include<algorithm>
using namespace std;

char str[20];
int mp[20];

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

bool next(int *a, int n)
{
	int index=-1, min=250;
	for(int i=n-1; i>0; --i)
	{
		for(int j=i+1; j<=n; ++j)
		{
			if(a[j]>a[i] && a[j]<min)
			{
				index = j;
				min = a[j];
			}
		}
		if(index!=-1)
		{
			swap(a[i],a[index]);
			sort(a+i+1,a+n+1);
			return true;
		}	
	}
	return false;
}

void pailie(int *a, int n)
{
	while(1)
	{
		for(int i=1; i<=n; ++i){
			if(a[i]%2==1){
				printf("%c", 'a'+(a[i]-1)/2);
			}
			else{
				printf("%c", 'A'+a[i]/2);
			}
		}
		
		printf("\n");
		bool flag = next(a, n);
		if(flag == 0)break;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		scanf("%s",&str[1]);
		
		int top=0;
		for(int i=1; str[i]; ++i){
			if(str[i]<='Z' && str[i]>='A'){
				mp[++top] = (str[i]-'A')*2;
			}
			else if(str[i]>='a' && str[i]<='z'){
				mp[++top] = (str[i]-'a')*2+1;
			}
		}
		sort(mp+1, mp+top+1);
		
		pailie(mp,top);
	}
	return 0;
}

