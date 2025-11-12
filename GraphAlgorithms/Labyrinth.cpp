#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m; // DON'T MAKE THEM IN MAIN

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
	for(string &i: mz) cin >> i;

	queue<int> q;
	int start = -1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(mz[i][j] == 'A'){
				q.push(i * m + j);
				start = i * m + j;
				break;
			}
	
	int fin = -1;
	string direc = "RDLU";
	while(!q.empty()){
		int idx = q.front();
		q.pop();
		int x = idx / m, y = idx % m;

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(check(nx, ny) && (mz[nx][ny] == '.' || mz[nx][ny] == 'B')){
				q.push(nx * m + ny);

				if(mz[nx][ny] == 'B') 
					fin = nx * m + ny;

				mz[nx][ny] = direc[i];
			}
		}
	}
	cout << (fin != -1 ? "YES" : "NO") << endl;
	if(fin == -1) return;
	string ans;
	while(fin != start){
		int x = fin / m, y = fin % m;

		ans += mz[x][y];
		int idx = dec(mz[x][y]);

		x += dx[idx]; y += dy[idx];
		fin = x * m + y;
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
