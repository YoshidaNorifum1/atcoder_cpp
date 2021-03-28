#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int INF = 1e9;

int main(){
 
  int n;
	std::cin>> n;
	vector<string> s;
	vector<int> p;
	int sum = 0;
	string res = "atcoder";

	for(int i = 0; i < n; i++){
		string temps;
		int tempp;
		cin >> temps >> tempp;
		s.push_back(temps);
		p.push_back(tempp);
		sum += tempp;
	}

  for(int i = 0; i < n; i++){
		if(p[i] > sum / 2){
			res = s[i];
		}
	}


	std::cout << res << endl;
 
	return 0;
}