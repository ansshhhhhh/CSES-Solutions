#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const int mod = 1e9 + 7;

class SegmentTree {
// For any Query l, r the range it search in is [l, r)
public:
	struct item{
		int val;
	};
	vector<item> value;
		
	item IDENTITY_ELEMENT = {0};
	int size;

	SegmentTree(int n){
		size = n;
		value.resize(4 * n, IDENTITY_ELEMENT);
	}

	item single (int val){
		return {val % mod};
	}

	item merge(item item1, item item2){
		return {(item1.val + item2.val) % mod};
	}

	void build(int x, int lx, int rx, vector<int>& a) {
		if(rx - lx <= 1){
			if(lx < size) value[x] = single(a[lx]);
			return;
		}
		
		int m = (lx + rx) / 2;

		build(2 * x + 1, lx, m, a);
		build(2 * x + 2, m, rx, a);

		value[x] = merge(value[2 * x + 1], value[2 * x + 2]);
	}

	void build(vector<int>& a) {
		build(0, 0, size, a);
	}
	
	void update(int i, int x, int lx, int rx, int val){
		if(rx - lx <= 1){
			value[x] = single(value[x].val + val);
			return;
		}
		
		int m = (lx + rx) / 2;

		if(i < m){
			update(i, 2 * x + 1, lx, m, val);
		}else{
			update(i, 2 * x + 2, m, rx, val);
		}

		value[x] = merge(value[2 * x + 1], value[2 * x + 2]);
	}

	void update(int i, int x){
		update(i, 0, 0, size, x);
	}

	item find(int x, int l, int r, int lx, int rx){
		if(rx <= l || r <= lx) return {IDENTITY_ELEMENT};
		if(l < lx && rx < r) return value[x];
		
		if(rx - lx <= 1) return value[x];

		int m = (lx + rx) / 2;

		item s1 = find(2 * x + 1, l, r, lx, m);
		item s2 = find(2 * x + 2, l, r, m, rx);

		return merge(s1, s2);
	}

	item find(int l, int r){
		return find(0, l, r, 0, size);
	}
};
		

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	set<int> st;
	for (int &val : a){
		cin >> val;
		st.insert(val);
	}
	
	map<int, int> mp;
	int it = 1;
	for(int i: st)
		mp[i] = it++;
	
	for(int &i: a) i = mp[i];
	
	SegmentTree sgt(it);
	
	int ans = 0;
	for(int i: a){
		int nw = max(sgt.find(0, i).val, 0LL) % mod;
		sgt.update(i, nw + 1);
		ans = (ans + nw + 1) % mod;
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
