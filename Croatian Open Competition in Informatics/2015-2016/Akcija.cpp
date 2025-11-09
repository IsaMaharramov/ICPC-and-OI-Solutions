#include<bits/stdc++.h>

/*

......

*/

using namespace std;

constexpr int sz = 2e5 + 5;

int n;
long long ans(0);

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int> A(n);
	for(auto &j : A) cin >> j, ans += j;
	sort(A.begin(), A.end());
	for(register int i = n - 3; i >= 0; i -= 3){
		ans -= A[i];
	}
	cout << ans << '\n';
	return 0;
}
/*


*/