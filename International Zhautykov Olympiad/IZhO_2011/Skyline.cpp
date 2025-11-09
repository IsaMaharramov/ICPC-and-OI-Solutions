#include<bits/stdc++.h>
using namespace std;

constexpr int inf = 1E9;

int n, h[305], dp[305][205][205];

int f(int i, int x, int y){
	
	if(i == n + 1) return 0;
	
	if(dp[i][x][y]) return dp[i][x][y];
	
	int res = inf;
	
	if(!x) res = f(i + 1, y, h[i+2]);
	else{
		
		res = min(res, f(i, x - 1, y) + 3);
		
		if(y){
			
			res = min(res, f(i, x - 1, y - 1) + 5);
			
			if(x <= min(y, h[i + 2])) res = min(res, f(i + 1, y - x, h[i + 2] - x) + 7 * x);
			
		}
		
	}
	
	return dp[i][x][y] = res;
	
}

/*
dp[i][x][y] -> dp[i][x+1][y] + 3,   dp[i][x+1][y+1] + 5, dp[i-1][]

dp[i][x-1][y] dp[i][x][y] + 3

dp[i][x-1][y-1]  dp[i][x][y] + 5

dp[i+1][y - x][h[i + 2] - x]  dp[i][x][y] + 7 * x; 	

*/



signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	register int j(1);
	loop:
		cin >> h[j++];
	if(j <= n) goto loop;
	
	for(register int i = 0; i <= n; ++i){
		for(register int j = 0; j < 205; ++j){
			for(register int m = 0; m < 205; ++m){
				dp[i][j][m] = inf;
			}
		}
	}
	
	dp[1][h[1]][h[2]] = 0;
	
	for(register int i = 1; i <= n; ++i){
		for(register int x = h[i]; x >= 0; --x){
			for(register int y = h[i+1]; y >= 0; --y){
				
				if(x) dp[i][x - 1][y] = min(dp[i][x - 1][y], dp[i][x][y] + 3);
				
				if(x && y) dp[i][x - 1][y - 1] = min(dp[i][x -1 ][y - 1], dp[i][x][y] + 5);
				
				if(x <= min(y, h[i + 2])) dp[i + 1][y - x][h[i + 2] - x] = min(dp[i + 1][y - x][h[i + 2] - x], dp[i][x][y] + 7 * x);
				
			}
		}
	}
	
	cout << dp[n][0][0] << '\n';
	
	return 0;
}