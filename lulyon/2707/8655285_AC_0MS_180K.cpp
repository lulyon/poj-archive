#include<iostream>
int main(int argc, char ** argv){
	int a,b,c,d;
	while(1){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(!a && !b && !c && !d)break;
		double r1 = std::min((double)c/a, (double)d/b);
		if(r1>1)r1 = 1;
		std::swap(a,b);
		double r2 = std::min((double)c/a, (double)d/b);
		if(r2>1)r2 = 1;
		if(r2<r1)r2 = r1;
		printf("%d%%\n", static_cast<int>(r2*100));
	}
	return 0;
}
