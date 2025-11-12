#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	
	vector<vector<int>> a (n);

	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		a[i] = {u, v, i};
	}
	
	sort(a.begin(), a.end());

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	vector<int> ans(n, 0);
	queue<int> q;
	
	int last = 0;

	for(int i = 0; i < n; i++){
		while(!pq.empty() && pq.top().first < a[i][0]){ 
			int free = pq.top().second;
			q.push(free);
			pq.pop();
		}

		if(q.empty()){
			last++;
			pq.push({a[i][1], last});
			ans[a[i][2]] = last;

			//cout << "Room " << last << " allocated to " << a[i][2] << endl;  
		}else{
			int room = q.front();
			q.pop();
			pq.push({a[i][1], room});
			ans[a[i][2]] = room;
			//cout << "Room " << room << " allocated to " << a[i][2] << endl;
		}
	}

	cout << last << endl;
	for(int i: ans)
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
