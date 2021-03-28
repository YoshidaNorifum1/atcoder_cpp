#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//const int INF = 1e9;

int main(){
 
  int n;
	vector<pair<int,int> > res;

	const int all = 2025;

	std::cin>> n ;
	int delta = all - n;

	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			if(i * j == delta) res.push_back(make_pair(j,i)); 
		}
	}

	sort(res.begin(), res.end());

  for(int i = 0; i < res.size(); i++){
		cout << res[i].first << " x " << res[i].second << endl;
	}

	return 0;
}