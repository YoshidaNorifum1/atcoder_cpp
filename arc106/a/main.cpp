#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <set>


using namespace std;

const int INF = 1e9;

int main(){
 
  long long int n;
	std::cin>> n ;

	long long int a,b;
	a = 1;

	for(int i=1; i<38; i++){
		a *= 3;
		b = 1;
		if(a > n)break;
		for(int j=1; j<26; j++){
			b *= 5;
			if(b>n)break;
			if(a + b == n){
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}

	std::cout << -1 << endl;
 
	return 0;
}