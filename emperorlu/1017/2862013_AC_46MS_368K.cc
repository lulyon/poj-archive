#include <iostream> 
using namespace std;
int Contain1[4] = { 0, 7, 6, 5 }; 
int Contain2[4] = { 0, 5, 3, 1 }; 
int nTotal;
int main() 
{ 
    int b1,b2,b3,b4,b5,b6; 
    while(1)
     { 
        cin>>b1>>b2>>b3>>b4>>b5>>b6;
        if(b1==0 && b2==0 && b3==0 && b4==0 && b5==0 && b6==0) 
		break;
	   nTotal = b6 + b5 + b4 + b3/ 4; 
	   if( b3 % 4) nTotal ++;
	   int c1; 		 
	   c1 = b5 * 11;  	
        c1 += Contain1[b3 % 4] ; 
	   int c2; 
	   c2 = b4 * 5;
	   c2 += Contain2[b3 % 4];
        if ( b2 <= c2 ) 
		c1 += (c2 - b2) * 4 ;
	    else
         {
		      nTotal += ( b2 - c2) / 9; 
		      int r2 = (b2 - c2) % 9;
		      if( r2 ) 
               {
		 		nTotal ++;
				c1 +=  36 - r2 * 4;
			 }
	       }
	if( b1 > c1 )
     {
		nTotal += ( b1 - c1 ) / 36;
		if(( b1 - c1) % 36 )
			nTotal ++;
	}
	cout << nTotal << endl;
    }
 }
