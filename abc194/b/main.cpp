#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int INF = 1e9;

int main(){
 
  int n;
	std::vector<int> a;
	std::vector<int> b;
	int rslt;
	bool f_issameMember = 0;
	
	std::cin>> n ;
	rslt = INF;

	for (int i = 0;i<n;i++){
		int tempa,tempb;
		std::cin >> tempa >> tempb;
		a.push_back(tempa);
		b.push_back(tempb);
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			rslt = std::min(rslt , i == j ? a[i] + b[j] : max(a[i] , b[j]));
		}
	}

	std::cout << rslt;
 
	return 0;
}