#include <iostream>
using namespace std;

int main () {
  int SC;
  cin >> SC;
  for( int S=1; S<=SC; S++ ){
    cout << "Scenario #" << S << ":" << endl;
    
    //--- Read the testcase data.
    int a, b;
    cin >> a >> b;
    
    //--- Dance...
    int left = 0, right = 0;
    while( a > 1  ||  b > 1 ){
      if( a > b ){
	int up = (a - 1) / b;
	left += up;
	a -= up * b;
      } else {
	int up = (b - 1) / a;
	right += up;
	b -= up * a;
      }
    }
    
    //--- Answer.
    cout << left << " " << right << endl << endl;
  }
}
