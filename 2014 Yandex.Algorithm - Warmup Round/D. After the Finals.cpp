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

int n, m, d[sz], mx[sz];

vector<pii> g[sz];

#define a3 array<int, 3>

void solve()
{
    cin >> n >> m;
    for (int i = 1, a, b, c; i <= m; ++i)
    {
        cin >> a >> b >> c;
        g[a].eb(pii{b, c}), g[b].eb(pii{a, c});
    }

    for (int i = 1; i <= n; ++i)
        d[i] = inf;

    priority_queue<a3, vector<a3>, greater<a3>> q;

    d[1] = 0;
    mx[1] = 0;
    q.push(a3{0, 0, 1}); // dist, -edge, node

    while (!q.empty())
    {
        a3 cur = q.top();
        q.pop();

        if (cur[0] > d[cur[2]] or (cur[0] == d[cur[2]] and -cur[1] < mx[cur[2]]))
            continue;

        for (auto &to : g[cur[2]])
        {
            if (d[cur[2]] + to.S < d[to.F])
            {
                d[to.F] = d[cur[2]] + to.S;
                mx[to.F] = mx[cur[2]] + 1;
                q.push(a3{d[to.F], -mx[to.F], to.F});
            }
            else if (d[cur[2]] + to.S == d[to.F])
            {
                if (mx[to.F] < mx[cur[2]] + 1)
                {
                    mx[to.F] = mx[cur[2]] + 1;
                    q.push(a3{d[to.F], -mx[to.F], to.F});
                }
            }
        }
    }

    cout << d[n] << ' ' << mx[n] << '\n';
    return;
}

#undef a3

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