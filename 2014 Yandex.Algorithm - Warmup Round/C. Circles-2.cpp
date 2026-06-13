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
constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << '\n';
}

map<ld, int> mp;

void solve()
{
    int n, res = 0;
    cin >> n;
    for (int i = 1, a, b, c; i <= n; ++i)
    {
        cin >> a >> b >> c;
        ld s = a + b + c;
        s /= 2;
        ld r2 = (s - a) * (s - b) * (s - c) / s;
        mp[r2]++;
        res = max(res, mp[r2]);
    }
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}