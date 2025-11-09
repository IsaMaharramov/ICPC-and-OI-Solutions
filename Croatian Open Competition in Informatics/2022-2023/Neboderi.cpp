/// ...
#include<bits/stdc++.h>
using namespace std;

constexpr int sz = 1e6 + 6;

int n, k, h[sz], f[20][sz], lg[sz];

long long pref[sz], ans;

inline int read();

inline int gcd(int a, int b){
	while(a) b%=a, swap(a, b);
	return b;
}

inline int get_ans(int l, int r){
	const int x = lg[r - l + 1];
	return gcd(f[x][l], f[x][r-(1<<x)+1]);
}

signed main(){
	
	n = read(), k = read();
	lg[0] = -1;
	for(register int i = 1; i <= n; ++i){
		h[i] = read();
		lg[i] = lg[i>>1] + 1;
		f[0][i] = h[i];
		pref[i] = pref[i-1] + h[i];
	}
	
	for(register int i = 1; i <= 19; ++i){
		
		for(register int j = 1; j + (1<<(i-1)) <= n; ++j){
			
			f[i][j] = gcd(f[i-1][j], f[i-1][j+(1<<(i-1))]);
			
		}
		
	}
		
	for(register int i = 1; i <= n - k + 1; ++i){
		
		int l(i);
		
		int gc = 0;
		
		bool flag = true;
		
		loop:
			
			int L{l}, R = n, mid, best{l};
				
			while(L <= R){
				mid = L + ((R - L) >> 1);
				if(get_ans(i, mid) == gc){
					L = mid + 1, best = mid;
				}else{
					R = mid - 1;
				}
			
			
			
			}
			
			register int j{best};
				
				
			gc = get_ans(i, j);
				
			if(j - i + 1 >= k) ans = max(ans, 1ll * gc * (pref[j] - pref[i-1]));
			
			gc = get_ans(i, min(j + 1, n));
				
			l = j + 1;			
			
			flag &= (l <= n);
			
		if(flag) goto loop;
		
		
		
	}
	
	cout << ans << '\n';
	
}

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
///...