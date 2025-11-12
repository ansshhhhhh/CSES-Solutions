#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
const ll INF = 1e18;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> p(n);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		p[i] = {u, -v, i};
	}

	sort(p.begin(), p.end());

	priority_queue<vector<int>> pq;
	
	vector<int> ans1(n, 0), ans2(n, 0);
	
	pq.push({-p[0][1], p[0][0], p[0][2]});

	for(int i = 1; i < n; i++){
		if(pq.top()[0] >= -p[i][1]){
			ans1[p[i][2]] = 1;
		}

		pq.push({-p[i][1], p[i][0], p[i][2]});
	}
	
	while(!pq.empty()) pq.pop();

	pq.push({-p[0][1], p[0][0], p[0][2]});

   for(int i = 1; i < n; i++){
      while(!pq.empty() && pq.top()[0] >= -p[i][1]){
         ans2[pq.top()[2]] = 1;
			pq.pop();
      }
      pq.push({-p[i][1], p[i][0], p[i][2]});
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
	int TET = 1;
	//cin >> TET;
	for (int i = 1; i <= TET; i++) {
		
		solve();
	}
	#ifdef ONDEVI
		cerr << endl << "finished in " << (double)(clock()) * 1.0 / CLOCKS_PER_SEC << " sec\n- - - - - - - - - -\nOutput:" << endl;
	#endif
}
