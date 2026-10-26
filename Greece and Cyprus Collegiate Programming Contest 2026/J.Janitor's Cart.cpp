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
#define ll long long
#define endl '\n'
#define ok puts("ok")

using namespace std;
using ld = long double;
using vi = vector<int>;
using vii = vector<pii>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int sz = 2e5 + 5;
constexpr int mod = 998244353;
// constexpr int inf = 1e18 + 7;

void show(vi &a)
{
    for (auto &to : a)
        cout << to << ' ';
    cout << endl;
    return;
}

int n, c, a[sz];

void solve()
{
    cin >> n >> c;
    int res(0ll);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] >= c)
        {
            res += (a[i] / c) * i * 2;
            a[i] %= c;
        }
    }

    register int i = n;
    while (!a[i] and i)
        --i;
    res += 2 * i;

    int cur = 0ll;
    for (; i; --i)
    {
        if (cur + a[i] < c)
        {
            cur += a[i];
        }
        else if ((cur + a[i]) == c)
        {
            --i;
            while (!a[i] and i)
                --i;
            res += 2 * i;
            cur = 0;
            ++i;
        }
        else
        {
            a[i] -= (c - cur);
            res += 2 * i;
            cur = 0;
            ++i;
        }
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