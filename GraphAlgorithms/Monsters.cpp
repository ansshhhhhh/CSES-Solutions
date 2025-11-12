#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m; // DON'T MAKE THEM IN SOLVE

bool check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int dec(char c){
	switch(c){
		case 'U': return 1;
		case 'D': return 3;
		case 'L': return 0;
		case 'R': return 2;
	}

	return 0;
}


void solve() {
	cin >> n >> m;

	vector<string> mz(n);
	for(string &s: mz) cin >> s;
	int sx = 0, sy = 0;
	queue<pair<int, int>> q;
	vector d(n, vector<int>(m, INF));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mz[i][j] == 'A') sx = i, sy = j;
			
			if(mz[i][j] == 'M'){
				q.push({i, j});
				d[i][j] = 0;
			}
		}
	}
	
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];

			if(check(nx, ny) && d[nx][ny] == INF && mz[nx][ny] == '.'){
				d[nx][ny] = d[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	 
	int ex = -1, ey = -1;
	
	vector da(n, vector<int>(m, INF));
	string direc = "RDLU";

	da[sx][sy] = 0;

	q.push({sx, sy});
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		
		if(x == 0 || y == 0 || x == n - 1 || y == m - 1) ex = x, ey = y;

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];

			if(check(nx, ny) && da[nx][ny] == INF && mz[nx][ny] == '.' && d[nx][ny] > da[x][y] + 1){
				da[nx][ny] = da[x][y] + 1;
				mz[nx][ny] = direc[i];
				q.push({nx, ny});
			}
		}

	}
	if(ex == -1){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	string ans;
	int x = ex, y = ey;
	while(x != sx || y != sy){
 
		ans += mz[x][y];
		int idx = dec(mz[x][y]);
 
		x += dx[idx]; y += dy[idx];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cerr << "- - - - - - - - - - - - -\nOutput:" << endl;
	int TET = 1;
	//cin >> TET;
	for (int i = 1; i <= TET; i++) {
		cerr << "Case #" << i << ": "; 
		solve();
	}
	cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
}
