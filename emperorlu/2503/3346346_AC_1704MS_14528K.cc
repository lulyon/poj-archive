#include<iostream>
#include <map>
using namespace std;

int main(){
	 map<string,string> mp;
	 char test,a[15],b[15];
	 while(1)
	 {
		test = getchar();
		if(test == '\n')break;
		a[0]=test;
		scanf("%s %s",&a[1],b);
		getchar();
		mp.insert(make_pair(b,a));
	 }
	
	 while(scanf("%s",b)!=EOF)
	 {
		if(mp.count(b))
		 	cout<<mp[b]<<endl;
		else
			printf("eh\n");
	 }
	 
 return 0;
}
