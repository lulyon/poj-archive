#include<iostream>
#include<math.h>
using namespace std;
const double PI = 2*acos(0);
int main(){
	int n;
	double x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&x,&y);
		printf("Property %d: This property will begin eroding in year %.0lf.\n",i,ceil(PI*(x*x+y*y)/100));
	}
	printf("END OF OUTPUT\n");
	return 0;
}
