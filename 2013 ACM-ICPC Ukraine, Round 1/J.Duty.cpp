#include "bits/stdc++.h"
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
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

constexpr int sz = 2e5 + 5;
constexpr int mod = 998244353;
constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << endl;
}

int n, m, fa[sz], sizel[sz], deg[sz];

int find_set(int v){
    return v == fa[v] ? v : fa[v] = find_set(fa[v]);
}

void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u ^ v){
        if(sizel[u] < sizel[v]) swap(u, v);
        fa[v] = fa[u];
        sizel[u] += sizel[v];
    }
    return;
}

int o_cnt[sz], is_on[sz];

void solve()
{
    cin >> n >> m;
    for(int i = 0; i <= n; ++i){
        fa[i] = (sizel[i] = 1, i);
    }
    for(int i = 1, u, v; i <= m; ++i){
        cin >> u >> v;
        ++deg[u];
        ++deg[v];
        union_set(u, v);
    }

    for(int i = 1; i <= n; ++i){
        if(deg[i]){
            int x = find_set(i);
            is_on[x] = (o_cnt[x] += deg[i] & 1, 1);
        }
    }

    int res{0ll}, comps{0ll};

    for(int i = 1; i <= n; ++i){
        if(find_set(i) == i and is_on[i]){
            ++comps;
            res += max(1ll, o_cnt[i] >> 1);
        }
    }

    if(comps == 1){
        for(int i = 1; i <= n; ++i){
            if(find_set(i) == i and is_on[i]){
                if(!o_cnt[i]) res = 0ll;
                break;
            }
        }
    }

    cout << res << endl;
    return;
}

signed main()
{
    SPEED;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}