#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll p10[19];
 
void solve() {
	ll k;
	cin >> k;
 
	ll d = 0;
	ll dig = 0;
 
	while(dig < k){
		d++;
		dig += d * 9 * p10[d - 1];
	}
 
	dig -= d * 9 * p10[d - 1];
 
	k -= dig;
 
	ll num = p10[d - 1]; 
	ll after = ((k - 1) / d);
	
	k -= after * d;
 
	num += after;
	
	ll x = d - k;
	
	while(x --> 0)
		num /= 10;
	
	
	cout << num % 10 << endl;
}
 
 
int main(){
	p10[0] = 1;
	for(int i = 1; i < 19; i++){
		p10[i] = p10[i - 1] * 10;
	}
	int t = 1;
	cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
