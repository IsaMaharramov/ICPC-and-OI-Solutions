#include<bits/stdc++.h>

using namespace std;

int N, M;
char grid[101][101];

int dx[ ] = {-1, 1, 0, 0}, dy[ ] = {0, 0, 1, -1};

bool vis[101][101];

bool OK(int& x, int& y){
	return (x >= 0 && y >= 0 && x < N && y < M);
}

inline void Dfs(int& x, int& y){
	vis[x][y] = 1;
	for (register int i = 0; i < 4; ++i){
		int tx = x + dx[i], ty = y + dy[i];
		if(!OK(tx, ty)) continue;
		if(vis[tx][ty]) continue;
		Dfs(tx, ty);
	}
	return;
}

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (register int i = 0; i < N; ++i){
		for (register int j = 0; j < M; ++j){
			cin >> grid[i][j];
			if(grid[i][j] ^ '*') vis[i][j] = 1;
		}
	}
	int ans(0);
	for (register int i = 0; i < N; ++i){
		for (register int j = 0; j < M; ++j){
			if(grid[i][j] == '*' && !vis[i][j]){
				Dfs(i, j); ++ans;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}