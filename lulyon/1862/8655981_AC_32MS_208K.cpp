//1862.cpp
#include<iostream>
#include<queue>
#include<math.h>

int main(int argc, char ** argv){
	int n;
	scanf("%d", &n);
	std::priority_queue<double> q;
	for(int i=0; i<n; ++i){
		double tmp;
		scanf("%lf", &tmp);
		q.push(tmp);
	}
	
	double t1, t2;
	while(q.size()>1){
		t1 = q.top();
		q.pop();
		t2 = q.top();
		q.pop();
		t1 = 2 * sqrt(t1*t2);
		q.push(t1);
	}
	printf("%.3lf\n",q.top());
	return 0;
}
