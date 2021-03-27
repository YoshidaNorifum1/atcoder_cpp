#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int INF = 1e9;

int main(){
 
  int n;
	std::cin>> n ;
	int res = 0;
	
	for(int a = 1;a < n;a++){
		for(int b = 1;b < n;b++){
			if(a * b < n){
				res++;
			}else{
				break;
			}
		}
	}

	std::cout << res << endl;
 
	return 0;
}