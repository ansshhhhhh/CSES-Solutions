#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& g){
	for(int i: g[node]){
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(i, vis, st, g);
		}
	}
	st.push(node);
}

vector<vector<int>> reverseGraph(vector<vector<int>> g){
	int n = g.size() - 1;
	vector<vector<int>> gr(n + 1);
	for(int u = 1; u <= n; u++){
		for(int v: g[u])
			gr[v].push_back(u);
	}
	return gr;
}

vector<vector<int>> stronglyConnectedComponents(vector<vector<int>>& g){
	int n = g.size() - 1;
	vector<int> vis(n + 1, 0);
	stack<int> st;
	vector<vector<int>> components;

	for(int i = 1; i <= n; i++) 
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(i, vis, st, g);
		}
	cout << endl;
	auto gr = reverseGraph(g);
	vis.assign(n + 1, 0);

	while(!st.empty()){
		int u = st.top();
		st.pop();
		if(vis[u]) continue;
		
		vector<int> component;
		vis[u] = 1;
		queue<int> q;
		q.push(u);

		while(!q.empty()){
			int node = q.front();
			q.pop();
			component.push_back(node);

			for(int v: gr[node]){
				if(vis[v] == 0){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
		components.push_back(component);
	}
	return components;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
	
		g[u].push_back(v);
		//g[v].push_back(u);
	}
	auto components = stronglyConnectedComponents(g);
	
	if(components.size() > 1){
		cout << "NO" << endl;
		cout <<  components[1][0] << " " << components[0][0] << endl;
		return;
	}
	cout << "YES" << endl;
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
