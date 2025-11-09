#include<bits/stdc++.h>

using namespace std;

int K, N;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> K >> N;
	for(register int i = 1; i < N; ++i){
		cout << i << '\n', K -= i;
	}
	cout << K << '\n';
	return 0;
}