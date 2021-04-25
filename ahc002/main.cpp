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
const int TIMELIMIT = CLOCKS_PER_SEC * 2.5;

unsigned int randXor()
{
  static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
  unsigned int t;
  t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

int si,sj;
vector<vector<int > > t(50, vector<int>(50));
vector<vector<int > > p(50, vector<int>(50));

struct STATE{
	vector<vector<bool > > visited;
	int i;
	int j;
	string res ;
	int score;
};

void same_tile(STATE& state,int i,int j){
	if(i - 1 >= 0 and t[i][j] == t[i-1][j])state.visited[i-1][j] = true;
	if(i + 1 < 50 and t[i][j] == t[i+1][j])state.visited[i+1][j] = true;
	if(j - 1 >= 0 and t[i][j] == t[i][j-1])state.visited[i][j-1] = true;
	if(j + 1 < 50 and t[i][j] == t[i][j+1])state.visited[i][j+1] = true;
}

void init(STATE& state){
	for(int i = 0;i < 50; i++){
		vector<bool> a(50,false);
		state.visited.push_back(a);
	}
	state.i = si;
	state.j = sj;
	state.visited[si][sj] = true;
	same_tile(state,si,sj);
	state.res = "";
	state.score = 0;
}
bool isMovable(STATE& state,int direction){
	bool res = false;
	int i = state.i;
	int j = state.j;
	switch (direction)
	{
	case 0:
			if(i-1 >= 0 and state.visited[i-1][j]==false){
				res = true;
			}
			break;
		case 1:
			if(j+1 < 50 and state.visited[i][j+1]==false){
				res = true;
			}
			break;
		case 2:
			if(i+1 < 50 and state.visited[i+1][j]==false){
				res = true;
			}
			break;
		case 3:
			if(j-1 >= 0 and state.visited[i][j-1]==false){
				res = true;
			}
			break;
		}
		return res;
}

void modify(STATE& state,int direction){
	int i = state.i;
	int j = state.j;
	switch (direction)
	{ case 0:
				state.visited[i-1][j] = true;
				same_tile(state,i-1,j);
				state.res.push_back('U');
				state.score += p[i-1][j];
				state.i = i - 1;
				state.j = j;
			break;
		case 1:
				state.visited[i][j+1] = true;
				same_tile(state,i,j+1);
				state.res.push_back('R');
				state.score += p[i][j+1];
				state.i = i;
				state.j = j + 1;
			break;
		case 2:
				state.visited[i+1][j] = true;
				same_tile(state,i+1,j);
				state.res.push_back('D');
				state.score += p[i+1][j];
				state.i = i + 1;
				state.j = j;
			break;
		case 3:
				state.visited[i][j-1] = true;
				same_tile(state,i,j-1);
				state.res.push_back('L');
				state.score += p[i][j-1];
				state.i = i;
				state.j = j - 1;
			break;
		}
	}

	int calc_score(STATE& state){ 
		int res = 0;
		return res;
	}

	void mountain(STATE& state){
		int time_start = clock();
		while(true){
		  int i = state.i;
		  int j = state.j;
			bool d0,d1,d2,d3;
			d0 = isMovable(state,0);
			d1 = isMovable(state,1);
			d2 = isMovable(state,2);
			d3 = isMovable(state,3);
			if(d0==false and d1==false and d2==false and d3==false)break;

			int direction;
			while(true){
				direction = randXor() % 4;
				if(direction == 0 and d0 == true){
					break;
				}
				if(direction == 1 and d1 == true){
					break;
				}
				if(direction == 2 and d2 == true){
					break;
				}
				if(direction == 3 and d3 == true){
					break;
				}
			}
			modify(state,direction);
	}
}
void sAnieling(){
	STATE state;
	init(state);
	int time_start = clock();
	double temp_start = 1;
	double temp_end = 0;
	while(true){
		int time_now = clock();
		if(time_now - time_start > TIMELIMIT)break;

		STATE new_state = state;
//		modify(new_state);
		int new_score = calc_score(new_state);
		int pre_score = calc_score(state);
		double temp = temp_start + (temp_end - temp_start) * (time_now - time_start) / TIMELIMIT;
		double prob = exp((new_score - pre_score) / temp);
		if(prob > (rand()%INF) / (double)INF){
			state = new_state;
		}
	}
}
int main(){
 
	cin >> si >> sj;

	for(int i = 0;i < 50; i++){
		for(int j = 0; j < 50; j++){
			cin >> t[i][j];
		}
	}
	for(int i = 0;i < 50; i++){
		for(int j = 0; j < 50; j++){
			cin >> p[i][j];
		}
	}

	int score = 0;
	string res = "";
	for(int i = 0;i < 30000;i++){
		STATE state;
		init(state);
		mountain(state);
		if(state.score > score){
			score = state.score;
			res = state.res;
		}
	}

	cout << res << endl;
 
	return 0;
}