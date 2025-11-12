#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

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
		return {val};
	}

	item merge(item item1, item item2){
		return {max(item1.val, item2.val)};
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
			value[x] = single(val);
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

	vector pro(n, vector<int>(3, 0));
	
	map<int, int> mp;
	vector<int> st;

	int last = 1;
	for(auto &i: pro){ 
		cin >> i[0] >> i[1] >> i[2];
		if(!mp[i[0]]){
			mp[i[0]] = 1;
			st.push_back(i[0]);
		}
		if(!mp[i[1]]){
			mp[i[1]] = 1;
			st.push_back(i[1]);
		}

	} 
	
	sort(st.begin(), st.end());

	for(int i = 0; i < st.size(); i++)
		mp[st[i]] = i;
	
	last = st.size();
	vector<int> dp(last, 0);
	SegmentTree sgt(last);
	sgt.build(dp);
	
	sort(pro.begin(), pro.end());
	int ans = 0;

	for(auto &i: pro){
		int l = mp[i[0]], r = mp[i[1]], v = i[2];
		int mxl = sgt.find(0, l).val;
		//cout << l << " " << r << " " << v << endl;
		
		dp[r] = max(dp[r], mxl + v);
		sgt.update(r, dp[r]);
		ans = max(ans, dp[r]);
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
