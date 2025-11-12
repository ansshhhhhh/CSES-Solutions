#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

const int N = 1001;
int d[N + 1][N + 1];
int cnt[N][N] = {0};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	memset(d, 0, sizeof(d));

	int src = 0, t = n + m + 1;

	for(int i = 0; i < k; i++){
		int u, v;
		cin >> u >> v;
		v = n + v;
		d[u][v] = 1;
	}

	for(int i = 1; i <= n; i++) d[0][i] = 1;
	for(int i = 1; i <= m; i++) d[n + i][t] = 1;
	
	int ans = 0;
	int c = 1;
	while(c){
		vector<int> from(t + 1, -1);
		vector<int> p;
		queue<pair<int, vector<int>>> q;
		q.push({0, {0}});
		while(!q.empty()){
			auto [node, path] = q.front();
			q.pop();
			
			if(node == t){
				p = path;
				break;
			}
			for(int i = 0; i <= n + m + 1; i++){
				if(d[node][i] >= c && i != from[node] && from[i] == -1){
					from[i] = node;
					path.push_back(i);
					q.push({i, path});
					path.pop_back();
				}
			}
		}
		if(from[t] == -1){
			c /= 2;
			continue;
		}
		int sz = p.size();
		for(int i = 1; i < sz; i++){
			int u = p[i - 1];
			int v = p[i];
			if(u < v){
				cnt[u][v]++;
			}else{
				cnt[v][u]--;
			}
			d[u][v]--;
			d[v][u]++;
		}
		ans++;
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(cnt[i][n + j]){
				cout << i << " " << j << endl;
			}
		}
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
