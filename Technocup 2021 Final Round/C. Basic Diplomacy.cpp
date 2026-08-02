#include "bits/stdc++.h"
#define oo 1000000001
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define y1 y_1
// #define int long long

using namespace std;
using ld = long double;
using vi = vector<int>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e9 + 7;

vector<int> f[sz];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, k; i < m; ++i)
    {
        cin >> k;
        f[i].resize(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> f[i][j];
        }
    }

    vi cnt(n + 1, 0), ans(m);

    for (int i = 0; i < m; ++i)
    {
        ans[i] = f[i][0];
        cnt[ans[i]]++;
    }

    int lm = (m + 1) >> 1, badguy{-1};

    for (int i = 1; i <= n; ++i)
    {
        if (cnt[i] > lm)
        {
            badguy = i;
            break;
        }
    }

    if (badguy != -1)
    {
        for (int i = 0; i < m; ++i)
        {
            if ((f[i][0] ^ badguy) or ((int)f[i].size() <= 1))
                continue;
            ans[i] = f[i][1];
            cnt[badguy]--;
            if (cnt[badguy] == lm)
                break;
        }
    }

    if (badguy != -1 and cnt[badguy] > lm)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
        for (auto &to : ans)
            cout << to << ' ';
        cout << '\n';
    }
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