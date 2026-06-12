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

constexpr int N = 1e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e9;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << '\n';
}

int head[N], to_edge[N << 1], nxt[N << 1], edge_cnt;
int deg[N], sz_down[N], md_down[N];
int sz_edge[N << 1], md_edge[N << 1];
int memo_prop[N << 1];
bool vis_prop[N << 1];
int n, M_current;

void add_edge(int u, int v)
{
    to_edge[edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}

void dfs1(int u, int p)
{
    sz_down[u] = 1;
    md_down[u] = (deg[u] == 1 ? 0 : inf);
    for (int e = head[u]; e != -1; e = nxt[e])
    {
        int v = to_edge[e];
        if (v == p)
            continue;
        dfs1(v, u);
        sz_down[u] += sz_down[v];
        md_down[u] = min(md_down[u], md_down[v] + 1);

        sz_edge[e] = sz_down[v];
        md_edge[e] = md_down[v];
    }
}

void dfs2(int u, int p, int up_sz, int up_md, int up_edge)
{
    if (p != -1)
    {
        sz_edge[up_edge ^ 1] = up_sz;
        md_edge[up_edge ^ 1] = up_md;
    }

    int min1 = inf, min2 = inf;
    int min1_count = 0;

    auto add_val = [&](int val)
    {
        if (val < min1)
        {
            min2 = min1;
            min1 = val;
            min1_count = 1;
        }
        else if (val == min1)
        {
            min1_count++;
        }
        else if (val < min2)
        {
            min2 = val;
        }
    };

    if (deg[u] == 1)
        add_val(0);
    if (p != -1)
        add_val(up_md + 1);

    for (int e = head[u]; e != -1; e = nxt[e])
    {
        int v = to_edge[e];
        if (v == p)
            continue;
        add_val(md_down[v] + 1);
    }

    for (int e = head[u]; e != -1; e = nxt[e])
    {
        int v = to_edge[e];
        if (v == p)
            continue;

        int pass_sz = n - sz_down[v];
        int val = md_down[v] + 1;
        int pass_md;
        if (val == min1 && min1_count == 1)
        {
            pass_md = min2;
        }
        else
        {
            pass_md = min1;
        }

        dfs2(v, u, pass_sz, pass_md, e);
    }
}

int limit(int e)
{
    if (sz_edge[e] > M_current)
        return md_edge[e] - 2;
    return inf;
}

int get_prop(int e)
{
    if (vis_prop[e])
        return memo_prop[e];
    vis_prop[e] = true;

    int u = to_edge[e ^ 1];
    int v = to_edge[e];

    int res = inf;
    for (int nxt_e = head[v]; nxt_e != -1; nxt_e = nxt[nxt_e])
    {
        if (nxt_e == (e ^ 1))
            continue;
        int l = limit(nxt_e);
        int p_val = get_prop(nxt_e);
        res = min(res, min(l, p_val));
    }

    if (res != inf)
        res -= 1;
    return memo_prop[e] = res;
}

bool check(int M)
{
    M_current = M;
    for (int i = 0; i < edge_cnt; ++i)
        vis_prop[i] = false;

    for (int u = 0; u < n; ++u)
    {
        if (deg[u] == 1)
        {
            int outgoing_edge = head[u];
            if (limit(outgoing_edge) >= 0 && get_prop(outgoing_edge) >= 0)
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n;
    edge_cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        head[i] = -1;
        deg[i] = 0;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
        deg[u]++;
        deg[v]++;
    }

    if (n <= 2)
    {
        cout << 1 << '\n';
        return;
    }

    dfs1(0, -1);
    dfs2(0, -1, 0, 0, -1);

    int l = 0, r = n - 1, best = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            best = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << n - best << '\n';
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