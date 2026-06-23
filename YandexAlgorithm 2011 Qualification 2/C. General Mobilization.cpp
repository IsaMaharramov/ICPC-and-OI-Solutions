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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int sz = 2e5 + 5;
constexpr int mod = 1e9 + 7;
// constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << '\n';
}

const int N = 5005;

int n, a[N], fa[N], up[N], ans[N];

vector<pii> g[N];

void Dfs(int node, int fath = 0)
{
    for (auto &to : g[node])
    {
        if (to.F == fath)
            continue;
        fa[to.F] = node;
        up[to.F] = to.S;
        Dfs(to.F, node);
    }
    return;
}

vector<pii> em;

short has[N][N << 1];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        em.eb(pii{a[i], i});
    }
    sort(all(em));
    for (int i = 1, u, v, c; i < n; ++i)
    {
        cin >> u >> v >> c;
        g[u].eb(pii{v, c}), g[v].eb(pii{u, c});
    }

    Dfs(1);
    int x, node;
    for (auto &to : em)
    {
        x = to.S;
        node = x;
        int d = 0;

        while (node ^ 1)
        {

            if (has[node][d] < up[node])
            {
                has[node][d]++;
                node = fa[node];
            }

            ++d;
        }

        ans[x] = d;
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];

    return;
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