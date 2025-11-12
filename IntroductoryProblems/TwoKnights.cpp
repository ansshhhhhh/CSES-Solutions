#include <bits/stdc++.h>
 
using namespace std;
 
long long count(int n){
	long long k = n * n;
 
	return k * (k - 1) / 2 - 4 * (n - 1) * (n - 2);
}
 
void solve() {
	int n;
	cin >> n;
 
	for(int i = 1; i <= n; i++){
		cout << count(i) << endl;
	}
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
