#include "bits/stdc++.h"
#define oo 1000000001
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define y1 y_1
#define int long long

using namespace std;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
// constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << '\n';
}

int n, a[sz], pref[sz];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pref[i] = __gcd(pref[i - 1], a[i]);
    }
    int res = pref[n], gc = 0;
    for (int i = n; i >= 1; --i)
    {
        res = max(res, __gcd(gc, pref[i - 1]));
        gc = __gcd(gc, a[i]);
    }
    cout << res << '\n';
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}