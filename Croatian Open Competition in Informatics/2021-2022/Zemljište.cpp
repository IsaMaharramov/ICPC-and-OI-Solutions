#include<bits/stdc++.h>
using namespace std;

constexpr long long inf = 1e18 + 7;

int r, s, a, b, c[501][501];

long long pref[501][501], ans;

inline long long get_cost(long long sm){
	return abs(sm - a) + abs(sm - b);
}

inline long long get_sm(int x1, int x2, int y1, int y2){
	long long res = pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
	//if(x1!=x2||y1!=y2) ans = min(ans, get_cost(res));
	return res;
}

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> r >> s >> a >> b;
	if(a>b) swap(a, b);
	for(register int i = 1; i <= r; ++i){
		for(register int j = 1; j <= s; ++j){
			cin >> c[i][j];
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + c[i][j]; 
		}
	}
	
	ans = pref[r][s];
	
	long long sm(0), cost(0), next_sm(0), cur_sm(0), cur_cost(inf), prev_cost(inf), next_cost(inf);
	
	for(register int x1 = 0; x1 <= r; ++x1){
		for(register int x2 = x1; x2 <= r; ++x2){
			
			int y1(0), y2(0);
			
			cur_cost = prev_cost = next_cost = inf;
			
			while(max(y1, y2) <= s){
				
				next_sm = get_sm(x1, x2, y1, y2 + 1);
				
				next_cost = get_cost(next_sm);
				
				
				if(next_cost > prev_cost){
					
					++y1;
					
					
					
				}else{
					
					++y2;
				
				}
				
				cur_sm = get_sm(x1, x2, y1, y2);
				
				cur_cost = get_cost(cur_sm);
				
				if(x1!=x2||y1!=y2) ans = min(ans, cur_cost);
				
				prev_cost = cur_cost;
					
			}
			
			
			
		}
	}
	
	cout << ans << '\n';
	
	
}