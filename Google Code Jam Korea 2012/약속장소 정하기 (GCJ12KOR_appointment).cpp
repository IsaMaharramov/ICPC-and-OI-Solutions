#include "bits/stdc++.h"
using namespace std;

#define int long long
constexpr int inf = 1e9 + 7;
constexpr int N = 10005;

int n, p, m, x[1 << 7], v[1 << 7], dist[N], cs;
vector<pair<int, int>> g[N];

void solve(){
    for(int i(0); i < N; ++i) g[i].clear();
    cin >> n >> p >> m;
    for(int i(0); i < p; ++i){
        cin >> x[i] >> v[i];
        --x[i];
    }

    for(int i(0), a, b, c, d; i < m; ++i){
        cin >> a >> b >> c;
        --c;
        while(--b){
            cin >> d;
            --d;
            g[c].emplace_back(pair<int, int>{d, a}), g[d].emplace_back(pair<int, int>{c, a});
            c = d;
        }
    }
    // return;
    memset(dist, 0, sizeof(dist));
    for(int i(0); i < p; ++i){
        priority_queue<pair<int, int>> q;
        vector<int> dd(n, inf);
        vector<bool> vis(n);
        q.emplace(pair<int, int>{0ll, x[i]});
        dd[x[i]] = 0ll;
        while(!q.empty()){
            int cur = q.top().second, dst = -q.top().first;
            q.pop();
            if(vis[cur]) continue;
            vis[cur] = true;
            for(const pair<int, int> &to : g[cur]){
                int nxt = to.first, dto = dst + to.second;
                if(vis[nxt] || dto >= dd[nxt]) continue;
                q.emplace(pair<int, int>{-dto, nxt});
                dd[nxt] = dto;
            }
        }
        for(int j(0); j < n; ++j) dist[j] = (vis[j] ? max(dist[j], dd[j] * v[i]) : inf);
    }
    int ans = *min_element(dist, dist + n);
    if(ans == inf) ans = -1;
    cout << "Case #" << (++cs) << ": " << ans << '\n';
    return;
}

signed main(){
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}