#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;


vector<int> postMax(vector<int>& a){
	int n = a.size();
	vector<int> b(n, 0);
	
	stack<int> st;

	for(int i = n - 1; i >= 0; i--){
		while(!st.empty() && a[st.top()] <= a[i]) st.pop();

		st.empty() ? b[i] = n : b[i] = st.top();
		st.push(i);
	}

	return b;
}
vector<int> preMax(vector<int>& a){
	int n = a.size();
	vector<int> b(n, 0);
	
	stack<int> st;
 
	for(int i = 0; i < n; i++){
		while(!st.empty() && a[st.top()] <= a[i]) st.pop();
 
		st.empty() ? b[i] = -1 : b[i] = st.top();
		st.push(i);
	}
 
	return b;
}


void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int &i: a) cin >> i;
	
	auto post = postMax(a);	
	auto pre = preMax(a);
	
	priority_queue<pair<int, int>> pq;
	
	for(int i = 0; i < n; i++) pq.push({a[i], i});

	vector<int> dp(n, 0);
	int ans = 1;
	while(!pq.empty()){
		int i = pq.top().second;
		pq.pop();

		int l = pre[i], r = post[i];
		dp[i] = 1;
		if(l >= 0) dp[i] = max(dp[i], dp[l] + 1);
		if(r < n) dp[i] = max(dp[i], dp[r] + 1);

		ans = max(ans, dp[i]);
	}
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
