#include<iostream>
using namespace std;

typedef struct INFO{
	int r,g,b;
}RGBType;

RGBType target[16];

int main(){
	int r,g,b;
	for(int i=0; i<16; ++i){
		scanf("%d%d%d",&r,&g,&b);
		if(r==-1 && g==-1 && b==-1)return 0;
		
		target[i].r = r;
		target[i].g = g;
		target[i].b = b;
	}
	
	while(1){
		scanf("%d%d%d",&r,&g,&b);
		if(r==-1 && g==-1 && b==-1)return 0;
		
		int d, mind, index;
		mind = (target[0].r-r)*(target[0].r-r)+
		(target[0].g-g)*(target[0].g-g)+
		(target[0].b-b)*(target[0].b-b);
		index = 0;
		
		for(int i=1; i<16; ++i){
			d = (target[i].r-r)*(target[i].r-r)+
			(target[i].g-g)*(target[i].g-g)+
			(target[i].b-b)*(target[i].b-b);
			
			if(d<mind){
				mind = d;
				index = i;
			}
		}
		
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",
		r,g,b,target[index].r,target[index].g,target[index].b);
	}
	return 0;
}

