#include<bits/stdc++.h>
using namespace std;
 
#define eb emplace_back
//#define int long long


inline int read() {
  //  opt = 0;
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    //if (ch == ' ') opt = 1;
    return x * f;
}

constexpr int sz = 1e5 + 5;
constexpr long long inf = (long long)1E18 + 7;

int n, s;

multiset<pair<int, int>> a[2005];

long long dp[2005];

signed main(){
	s = read(), n = read();
	for(register int i = 1, v, w, k; i <= n; ++i){
		v = read(), w = read(), k = read();
		k = min(k, s / w);
		a[w].insert({-v, -k});
	}
	
	for(register int i = 1; i <= 2000; ++i) dp[i] = -inf;
	
	for(register int i = 1; i <= s; ++i){
		
		int tot(0);
		
		for(auto it = a[i].begin(); it != a[i].end(); ++it){
			
			int k = it->second, v = it->first;
			k *= -1, v *= -1;
			
			if(tot > 2000) break;
			
			tot += k;
			
			while(k--){
				
				for(register int j = s; j >= i; --j) dp[j] = max(dp[j], dp[j - i] + v);
				
			}
			
		}
		
	}
	
	cout << *max_element(dp, dp+s+1) << '\n';
	
	
}