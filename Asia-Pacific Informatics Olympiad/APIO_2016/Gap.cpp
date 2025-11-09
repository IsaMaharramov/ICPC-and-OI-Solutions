#include "gap.h"
#include<bits/stdc++.h>
using namespace std;

long long findGap(int T, int N){
	
	long long mn, mx, ans = -((long long)1E18 + 7);
	
	vector<long long> a(N+1, 0ll);
	
	MinMax(0ll, (long long)1E18, &mn, &mx);
	
	a[1] = mn, a[N] = mx;
	
	if(T == 1 || N <= 10){
	
		for(register int i = 2; i <= N/2 + (N & 1); ++i){
		
			long long l = a[i-1], r = a[N - (i-1) + 1];
		
			MinMax(l+1, r-1, &mn, &mx); // called by reference
	
			a[i] = mn, a[N - i + 1] = mx;
		
		}
		
		for(register int i = 2; i <= N; ++i) ans = max(ans, a[i] - a[i-1]);
		
		return ans;
		
	}
	
	long long blo = (mx - mn) / (N - 1) + 1;
	
 	long long pmx{a[1]};
 	
	for(long long j = a[1]; j <= a[N]; j += blo){
		
 		MinMax(j, j + blo - 1, &mn, &mx);
 		
 		if(mn == -1) continue;
		 	
 		ans = max(ans, mn - pmx);
 		
 		pmx = mx;
 		
 		
	}
 	
 	return ans;
 	
 	
 	
 	
 	
}