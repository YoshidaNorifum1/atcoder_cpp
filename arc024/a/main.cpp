#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int INF = 1e9;

int main(){
 
  int L,R;
	std::cin>> L >> R ;
	int l[45];
	int res = 0;

	for(int i = 0;i < 45;i++){
		l[i] = 0;
	}

	for(int i = 0;i < L;i++){
		int a;
		cin >> a;
		l[a] ++;
	}

	for(int i = 0;i < R;i++){
		int a;
		cin >> a;
		if(l[a] - 1 >= 0){
			l[a]--;
			res++;
		}
	}

	cout << res << endl;
 
	return 0;
}