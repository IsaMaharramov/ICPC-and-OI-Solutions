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

constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << '\n';
}

int n, a[1 << 17], dp[1 << 17];
vector<int> d[1 << 17];

void solve()
{
    for (int i = 1; i < (1 << 17); ++i)
    {
        dp[i] = inf;
        for (int j = i; j < (1 << 17); j += i)
        {
            d[j].eb(i);
        }
    }
    cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0, x; i <= n; ++i)
    {

        for (auto to : d[a[i]])
        {
            x = i - to;
            if (x < 0)
                break;
            dp[i] = min(dp[i], dp[x] + 1);
        }
    }
    cout << (dp[n] == inf ? -1 : dp[n]) << '\n';
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