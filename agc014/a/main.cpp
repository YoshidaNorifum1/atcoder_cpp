#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <set>


using namespace std;

const int INF = 1e9;

int main(){
 
  int a,b,c;
	std::cin>> a >> b >> c;
	int res = 0;

	if(a == b && b == c && a % 2 == 0){
		res = -1;
	}else{
		while((a % 2 == 0) && (b % 2 == 0) && (c % 2 == 0)){
			int tmpa = (b + c) / 2;
			int tmpb = (a + c) / 2;
			int tmpc = (a + b) / 2;
			a = tmpa;
			b = tmpb;
			c = tmpc;
			res += 1;
		}
	}

	std::cout << res << endl;
 
	return 0;
}

