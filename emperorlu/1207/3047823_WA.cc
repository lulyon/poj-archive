#include <iostream> 
using namespace std; 
const int LENGTH = 100000; 
int *A; 
int calc(int x)
{
 int temp = x; 

 int count = 0;
 while ( 1 )
 {
  if ( x < LENGTH && A[x]!=0)
  {
   A[temp] = count + A[x];
   break;
  } 

  else
  if ( x % 2 == 1 )
  {
    x = 3*x+1;
  }
  else x /= 2;
  count++;
 } 


 return A[temp];
}
int main()
{
 int M,N;
 int i; 


 A = new int[LENGTH];
 memset(A,0,sizeof(int)*LENGTH);
 
 A[1] = 1; 

 for ( i = 1 ; i < LENGTH ; i++ )
  A[i] = calc( i );
 
 cin >> M;
 while ( M != 0 )
 {
  cin >> N; 

  if ( M > N ) 
  {
   M += N;
   N = M - N;
   M -= M;
  }
  
//  cout << M <<' ' << N <<endl; 

  

  

  int max = 0 ;
  
  for ( i = M ; i <= N ; i++ )
  {
   if ( A[i] > max ) max = A[i];
    //  cout <<i <<' ' <<A[i] <<endl;
  } 

  cout << max <<endl; 

  cin >> M;
 } 
 return 0;
}