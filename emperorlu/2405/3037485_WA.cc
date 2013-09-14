#include<iostream>
#include<math.h>
using namespace std;
int main()
{
   double D,d,v;
   const double pi=3.1415926;
   cin>>D>>v;
   d=pow((D*D*D-6*v/pi),1/3.0);
   printf("%.3lf\n",d);
   return 0;
}