
#include<iostream>

using namespace std;

__int64 display[10010];

int main()
{
        __int64 p1,p2,p3,num,i,counter,min;
	scanf("%I64d%I64d%I64d%I64d",&p1,&p2,&p3,&num);
       
	if(p1>p2)p1^=p2^=p1^=p2;
	if(p1>p3)p1^=p3^=p1^=p3;
	if(p2>p3)p2^=p3^=p2^=p3;
        
	display[0]=1;
	display[1]=p1;
	counter=2;
	while(counter<=num)
        {
		for(i=counter-1;display[i]*p1>display[counter-1]&&i>=0;i--);
		min=display[i+1]*p1;
		for(i=counter-1;display[i]*p2>display[counter-1]&&i>=0;i--);
		if(display[i+1]*p2<min)min=display[i+1]*p2;
		for(i=counter-1;display[i]*p3>display[counter-1]&&i>=0;i--);
		if(display[i+1]*p3<min)min=display[i+1]*p3;
		display[counter]=min;
		counter++;
	}
	printf("%I64d\n",display[num]);
        
        return 0;
}
