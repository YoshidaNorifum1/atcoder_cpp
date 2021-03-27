#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

const int INF = 1e9;

int main(){
 
  string s;

	cin >> s ;
	bool res = true;

	for(int i = 0 ; i < s.length() ; i += 2){
		if ( isupper(s[i])){
			res = false;
			break;
		}
	}

	if(res){
		for(int i = 1 ; i < s.length() ; i += 2){
			if ( !isupper(s[i])){
				res = false;
				break;
			}
		}
	}

	cout << (res? "Yes" : "No") << endl;
 
	return 0;
}