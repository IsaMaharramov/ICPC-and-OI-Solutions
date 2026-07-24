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

constexpr int sz = 1e6 + 6;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;

vector<pii> to[10] = {
    {{1, 4}},         // 0000   0
    {{2, 3}, {4, 1}}, // 0001   1
    {{5, 2}, {3, 2}}, // 0011   2
    {{0, 1}, {6, 3}}, // 0111   3
    {{5, 3}},         // 0002   4
    {{6, 2}, {7, 1}}, // 0012   5
    {{1, 1}, {8, 2}}, // 0112   6
    {{8, 2}},         // 0022   7
    {{9, 1}, {2, 1}}, // 0122   8
    {{3, 1}}          // 0222   9
};

int n, ans[sz];

array<int, 10> dp, new_dp;

void precomp()
{
    ans[0] = dp[0] = 1;

    for (int i = 1; i < (sz << 2); ++i)
    {
        new_dp.fill(0);

        for (int j = 0; j < 10; ++j)
        {
            if (dp[j] > 0)
            {
                for (auto &w : to[j])
                    new_dp[w.F] = (new_dp[w.F] + dp[j] * w.S) % mod;
            }
        }

        dp = new_dp;
        if (i % 4 == 0)
            ans[i >> 2] = dp[0];
    }
    return;
}

void solve()
{
    cout << (cin >> n, ans[n]) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    precomp();
    while (t--)
        solve();
    return 0;
}