#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;

//int ancestor[N + 1][33];

void solve() {
    int V, Q;
	 cin >> V >> Q;

    int maxN = 33;
   
	vector ancestor(maxN, vector<int>(V + 1));
    for (int i = 1; i <= V; i++) {
       int v;
		 cin >> v;
		 ancestor[0][i] = v;
    }

    for (int j = 1; j < maxN; j++) {
        for (int i = 1; i <= V; i++) {
            ancestor[j][i] = ancestor[j - 1][ancestor[j - 1][i]];
        }
    }

	 vector<int> ans;
    while(Q--){
		 int x, k;
		 cin >> x >> k;
		 int node = x;

		 for (int i = maxN - 1; i >= 0; i--) {
			 if (k & (1 << i)) {
				if (ancestor[i][node] == -1) break;

					node = ancestor[i][node];
					k -= (1 << i);
			  }
			  if(!k) break;
		 }
		ans.push_back(node);	 
	 }
	 for(int i: ans)
		 cout << i << endl;
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
