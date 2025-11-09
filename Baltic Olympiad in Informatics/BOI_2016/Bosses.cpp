
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define F first
#define S second

constexpr int sz = 5005;
constexpr int inf = 1e18 + 7;

int n, cnt, cost, ans = inf;
vector<int> g[sz];
bitset<sz> vis;

void bfs(int root){
  queue<pii> q;
  vis[root] = (q.push({root, 1}), 1);
  while(!q.empty()){
    pii cur = q.front();
    cost += (q.pop(), ++cnt, cur.S);
    for(int &u : g[cur.F]) if(!vis[u]) vis[u] = (q.push({u, cur.S + 1}), 1);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for(int i = 1, k; i <= n; ++i){
    cin >> k;
    for(int j = 1, u; j <= k; ++j){
      cin >> u;
      g[u].emplace_back(i);
    }
  }
  for(int i = 1; i <= n; ++i){
    vis.reset();
    cost = cnt = 0ll;
    bfs(i);
    if(cnt == n) ans = min(ans, cost);
  }
  cout << ans << '\n';
  return 0;
}
