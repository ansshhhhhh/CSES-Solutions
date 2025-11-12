#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;

/*
	To use "find_by_order(k)" // returns kth smallest element pointer
			"order_of_key(k)"  // return no of element less than k
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename Key, typename Value>
using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		a[i] = {u, - v, i};
	}

	sort(a.begin(), a.end());

	ordered_set<pair<int, int>> st;
	
	vector<int> ans1(n, 0);
	vector<int> ans2(n, 0);

	for(int i = 0; i < n; i++){
		ans1[a[i][2]] = st.size() - st.order_of_key({-a[i][1], -i});
		st.insert({-a[i][1], -i});
	}
	
	st.clear();

	for(int i = n - 1; i >= 0; i--){
		ans2[a[i][2]] = st.order_of_key({-a[i][1], -i});
		st.insert({-a[i][1], -i});
	}
	for(int i: ans2)
		cout << i << " ";
	
	cout << endl;

	for(int i: ans1)
		cout << i << " ";

}

int main() {
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
