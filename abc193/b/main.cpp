#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int INF = 1e9;

int main(){
 
  int n;
	vector<int> a; 
	vector<int> p; 
	vector<int> x; 
	int res = INF;

	std::cin>> n ;

	for(int i = 0;i < n;i++){
		int tempa,tempp,tempx;
		cin >> tempa >> tempp >> tempx;
		a.push_back(tempa);
		p.push_back(tempp);
		x.push_back(tempx);
	}

	for(int i = 0;i < n;i++){
		if (x[i] > a[i]){
			res = min(res,p[i]);
		}
	}

	if(res == INF)res = -1;

	std::cout << res;
 
	return 0;
}