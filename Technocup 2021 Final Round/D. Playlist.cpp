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

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    vi nxt(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        nxt[i] = (i % n) + 1;
    }

    vector<bool> vis(n + 1, false);
    queue<pii> q;

    for (int i = 1; i <= n; ++i)
    {
        q.push({i, nxt[i]});
    }

    vi ans;

    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        int i = cur.F, to = cur.S;

        if (vis[i] or vis[to] or nxt[i] ^ to)
            continue;

        if (__gcd(a[i], a[to]) ^ 1)
            continue;

        vis[to] = 1;
        ans.eb(to);
        nxt[i] = nxt[to];
        q.push({i, nxt[i]});
    }

    cout << (int)ans.size() << ' ';
    for (auto &to : ans)
        cout << to << ' ';
    cout << '\n';
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