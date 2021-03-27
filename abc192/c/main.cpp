#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int INF = 1e9;

int main(){
 
   int n,k;
	 cin >> n >> k;

	 string s1 = to_string(n);
	 istringstream ss;

	 for(int i = 0; i < k; i++){
		 int g1,g2;
		 sort(s1.begin(), s1.end(), greater<char>());
		 ss = istringstream(s1);
		 ss >> g1;

		 sort(s1.begin(), s1.end());
		 ss = istringstream(s1);
		 ss >> g2;

		 s1 = to_string(g1 - g2);
	 }
	 
	 cout << s1 << endl;
 
	 return 0;
}