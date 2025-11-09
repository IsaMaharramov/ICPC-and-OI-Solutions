#include<bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	vector<int> A(N+1, 0), B(N+1, 0);
	for(register int i(1); i <= N; ++i) cin >> B[i], B[i] *= i;
	for(register int i = 1; i <= N; ++i){
		A[i] = B[i] - B[i-1];
	}
	for(register int i = 1; i <= N; ++i){
		cout << A[i] << ' ';
	}
	cout << '\n';
	return 0;
}