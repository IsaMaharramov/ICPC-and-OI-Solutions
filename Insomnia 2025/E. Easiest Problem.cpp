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

int n;
string s;

void solve()
{
    cin >> n >> s;
    int res = 0;
    array<int, 2> dp = {-inf, -inf};
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            dp[0] = max({0ll, dp[0] + 1, dp[1]});
        else
            dp[1] = max({0ll, dp[1] + 1, dp[0]});
    }
    cout << max({0ll, dp[0], dp[1]}) << '\n';
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