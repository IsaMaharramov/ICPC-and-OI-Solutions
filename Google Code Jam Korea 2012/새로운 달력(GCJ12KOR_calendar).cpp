#include "bits/stdc++.h"
using namespace std;

#define int long long

constexpr int sz = 2e5 + 5;

int n, a, b, c, ans, k;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a >> b >> c;
        k = c / __gcd(b % c, c);
        ans = (a * b) / c + (a / k) * (k - 1) + a % k;
        cout << "Case #" << i << ": " << ans << '\n';
    }
    return;
}

signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}