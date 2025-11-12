#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

int vis[8][8];

bool solved = false;

int dx[] = {1, 1, -1, -1, 2, -2, 2, -2};
int dy[] = {2, -2, 2, -2, 1, 1, -1, -1};

bool check(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8 && vis[x][y] == 0;
}

int valid_moves(int x, int y){
	int cnt = 0;
	for(int i = 0; i < 8; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(check(nx, ny)) cnt++;
	}
	return cnt;
}

bool completed(){
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			if(!vis[i][j]) return false;
	return true;
}

void count(int x, int y, int turn){
	if(!valid_moves(x, y)){
		solved = completed();
		return;
	}
	if(solved) return;
	
	vector<tuple<int, int, int>> moves;
	
	for(int i = 0; i < 8; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(check(nx, ny)){
			int cnt = valid_moves(nx, ny);
			moves.push_back({cnt, nx, ny});
		}
	}
	sort(moves.begin(), moves.end());

	for(auto [_, nx, ny]: moves){
		vis[nx][ny] = turn;
		count(nx, ny, turn + 1);
		if(solved) return;
		vis[nx][ny] = 0;
	} 
}

void solve() {
	int x, y;
	cin >> y >> x;
	x--;
	y--;
	memset(vis, 0, sizeof(vis));
	vis[x][y] = 1;

	count(x, y, 2);

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << vis[i][j] << " ";
		}
		cout << endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << "\nOutput:\n- - - - - - - - - - - - -" << endl;
	int TET = 1;
	//cin >> TET;
	for (int i = 1; i <= TET; i++) {
		cerr << "Case #" << i << ": "; 
		solve();
	}
	cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
}
