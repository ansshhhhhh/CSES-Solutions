#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
 
	int mx = 0;
	long long ans = 0;
 
	for(int i = 0; i < n; i++){
		int x; cin >> x;
 
		mx = max(mx, x);
		ans += mx - x;
	}
 
	cout << ans;
}
