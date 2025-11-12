#include <bits/stdc++.h>
 
using namespace std;
 
 
void solve() {
	int n;
	cin >> n;
 
	vector<int> p(n);
 
	for(int &i: p) cin >> i;
 
	long ans = 1e12;
 
	long P = 1LL << n;
 
	for(long i = 0; i < P; i++){
		long s1 = 0, s2 = 0;
		for(int j = 0; j < n; j++){
			if(i & (1LL << j)){
				s1 += p[j];
			}else
				s2 += p[j];
		}
 
		ans = min(ans, abs(s2 - s1));
	}
	
	cout << ans << endl;
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
