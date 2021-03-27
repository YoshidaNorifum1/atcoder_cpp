#include <iostream>
#include <cmath>
using namespace std;

int main(){
 
  string s;
	cin>> s ;

  cout << s.substr(0,s.find('.'));
 
	return 0;
}