#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

//const int INF = 1e9;

int main(){
 
  string n;
	set<char> s;
	std::cin>> n ;

	for(int i = 0;i < 4; i++) s.insert(n[i]); 


	std::cout << (s.size() == 1 ? "SAME" : "DIFFERENT") << endl;
 
	return 0;
}