#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

template <typename T>
bool chmax(T &a, const T &b){
	if(a < b){
		a = b;
		return true;
	}
		return false;
}

template <typename T>
bool chmin(T &a, const T &b){
	if(a > b){
		a = b;
		return true;
	}
		return false;
}

const int INF = 1e9;

int main(){
 
  int a,b;
	std::cin>> a >> b;
	a = abs(a - b);
	chmin(a,10-a);

	std::cout << a << endl;
 
	return 0;
}