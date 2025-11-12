#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int n;
	cin >> n;
	
	vector<vector<int>> stp(n, vector<int>(n, -1));
 
	stp[0][0] = 0;
 
	queue<pair<int, int>> q;
 
	q.push({0, 0});
 
	int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
	int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
 
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
 
		for(int i = 0; i < 8; i++){
			int nx = x + dx[i], ny = y + dy[i];
 
			if(nx >= 0 && ny >= 0 && nx < n && ny < n && stp[nx][ny] == -1){
				stp[nx][ny] = stp[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << stp[i][j] << " ";
		}
		cout << endl;
	}
}
 
 
int main(){
	int t = 1;
	//cin >> t;
 
	while(t--)
		solve();
	
	return 0;
}

