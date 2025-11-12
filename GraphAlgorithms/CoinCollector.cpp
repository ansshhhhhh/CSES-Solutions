#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;



void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& g){
	for(int i: g[node])
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(i, vis, st, g);
		}
	st.push(node);
}
vector<vector<int>> reverseGraph(vector<vector<int>> g){
	int n = g.size() - 1;
	vector<vector<int>> gr(n + 1);
	for(int u = 1; u <= n; u++)
		for(int v: g[u])
			gr[v].push_back(u);
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
	auto gr = reverseGraph(g);
	vis.assign(n + 1, 0);
	while(!st.empty()){
		int u = st.top(); st.pop();
		if(vis[u]) continue;
		vector<int> component;
		vis[u] = 1;
		queue<int> q;
		q.push(u);
		while(!q.empty()){
			int node = q.front(); q.pop();
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

void dfs2(int node, vector<bool>& vis, vector<int>& dp, vector<vector<int>>& g, vector<int>& a){
	int mx = 0;
	for(int v: g[node]){
		if(!vis[v]){
			vis[v] = true;
			dfs2(v, vis, dp, g, a);
		}
		mx = max(mx, dp[v]);
	}
	dp[node] = a[node] + mx;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> a(n + 1, 0);
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
	
		g[u].push_back(v);
		//g[v].push_back(u);
	}
	auto components = stronglyConnectedComponents(g);
	
	int sz = components.size();
	
	vector<int> cmp(n + 1, -1), ac(sz + 1, 0);
	int it = 1;
	for(auto i: components){
		for(int node: i){
			cmp[node] = it;
			ac[it] += a[node];
		}
		it++;
	}
	
	set<pair<int, int>> edges;
	for(int u = 1; u <= n; u++)
		for(int v: g[u])
			edges.insert({cmp[u], cmp[v]});
	
	vector<vector<int>> graph(sz + 1);
	for(auto [u, v]: edges)
		graph[u].push_back(v);

	vector<int> dp(sz + 1, 0);
	vector<bool> vis2(sz + 1, 0);

	int ans = 0;
	for(int i = 1; i <= sz; i++){
		if(!vis2[i]){
			vis2[i] = 1;
			dfs2(i, vis2, dp, graph, ac);
		}
		ans = max(ans, dp[i]);
	}
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
