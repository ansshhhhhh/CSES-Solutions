#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

string s;
bool vis[7][7];
int ans = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n = 7, m = 7; // DON'T MAKE THEM IN SOLVE

string pos = "RDLU";

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}

void dfs(int x, int y, int step){
	if(step == 48 || (x == 6 && y == 0)){
		ans += (step == 48 && x == 6 && y == 0);
		return;
	}
	bool u = x == 0 || vis[x - 1][y], d = x == 6 || vis[x + 1][y], l = y == 0 || vis[x][y - 1], r = y == 6 || vis[x][y + 1];

	if((u && d && !l && !r) || (l && r && !u && !d)) return;	
	
	for(int i = 0; i < 4; i++){
		if(s[step] != '?' && s[step] != pos[i]) continue;
		int nx = x + dx[i], ny = y + dy[i];

		if(check(nx, ny)){
			vis[nx][ny] = 1;
			dfs(nx, ny, step + 1);
			vis[nx][ny] = 0;
		}
	}
}

void solve() {
	cin >> s;
	vis[0][0] = 1;
	dfs(0, 0, 0);
	cout << ans << endl;
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
