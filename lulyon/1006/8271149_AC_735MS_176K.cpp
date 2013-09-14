#include<iostream>
using namespace std;
int main(){
	int t,p,e,i,d,w;
	t=0;
	while(1){
		scanf("%d%d%d%d",&p,&e,&i,&d);
		if(p==-1 && e==-1 && i==-1 && d==-1)break;
		
		for(w=1;;++w){
			if((w+d-p)%23==0 && (w+d-e)%28==0 && (w+d-i)%33==0)
				break;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n",++t,w);
	}
	return 0;
}
