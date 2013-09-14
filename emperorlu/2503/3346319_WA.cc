#include<iostream>
#include <map>
using namespace std;

int main(){
	 map<char *,char *> mp;
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
	 	printf("%s\n",mp[b]);
	 
 return 0;
}
