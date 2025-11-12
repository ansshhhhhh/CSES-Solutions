#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	cin >> n;
 
	vector<bool> chk(n + 1, true);
 
	for(int i = 1; i < n; i++){
		int x;
		cin >> x;
 
		chk[x] = false;
	}
 
	for(int i = 1; i <= n; i++)
		if(chk[i]) cout << i;
}

