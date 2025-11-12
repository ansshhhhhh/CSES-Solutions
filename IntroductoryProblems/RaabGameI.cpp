#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int n, a, b;
	cin >> n >> a >> b;
 
	if(n < (a + b) || n == max(a, b) || (a != b && (a == 0 || b == 0))){
		cout << "NO" << endl;
		return;
	}
 
	cout << "YES" << endl;
 
	int eq = n - (a + b);
 
	for(int i = n; i > 0; i--)
		cout << i << " ";
	
	cout << endl;
 
	for(int i = 0; i < eq; i++)
      cout << n - i << " ";
   
 
	for(int i = a; i > 0; i--)
		cout << i << " ";
	
	for(int i = n - eq; i > a; i--)
		cout << i << " ";
	
	cout << endl;
}
 
 
int main(){
	int t = 1;
	cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}
