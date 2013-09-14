#include<iostream>
using namespace std;
bool visited[10000];

int compute(int n){
	int sum = n;
	while(n!=0){
		sum += n%10;
		n/=10;
	}
	return sum;
}

int main(){
	for(int i=0; i<10000; ++i){
		visited[i] = 0;
	}
	int result;
	for(int i=1; i<10000; ++i){
		if(!visited[i]){
			result = i;
			while(1){
				result = compute(result);
				if(result>=10000 && visited[result]){
					break;
				}
				else{
					visited[result] = 1;
				}
			}
		}
	}
	
	for(int i=1; i<10000; ++i){
		if(!visited[i]){
			printf("%d\n",i);
		}
	}
	
	return 0;
}

