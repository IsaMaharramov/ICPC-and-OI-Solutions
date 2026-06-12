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
#define endl '\n'

using namespace std;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int sz = 1e6 + 5;
constexpr int mod = 1e9 + 7;
// constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << endl;
}

int n, c[1 << 8], dp[1 << 8][1 << 8];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }

    for (int len = 1; len <= n; ++len)
    {
        for (int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;
            if (l == r)
            {
                dp[l][r] = 1;
            }
            else
            {
                dp[l][r] = dp[l + 1][r] + 1;

                for (int i = l + 1; i <= r; ++i)
                {
                    if (c[l] == c[i])
                    {
                        int inx = (l + 1 <= i - 1 ? dp[l + 1][i - 1] : 0ll);
                        int outx = (i + 1 <= r ? dp[i + 1][r] : 0ll);
                        dp[l][r] = min(dp[l][r], inx + outx);
                    }
                }
            }
        }
    }
    cout << dp[1][n] << endl;
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