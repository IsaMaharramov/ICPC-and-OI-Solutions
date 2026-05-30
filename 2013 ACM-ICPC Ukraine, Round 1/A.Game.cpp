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

int g[5] = {0, 0, 1, 1, 2};

void solve()
{   
    int n = (cin >> n, n);
    vector<int> a(n);
    int res = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        res ^= g[a[i] % 5];
    }
    /*
    G(x) = mex({G(x - 2), G(x - 3)})

    x = 0 -> G(0) = 0
    x = 1 -> G(1) = 0
    x = 2 -> G(2) = 1
    x = 3 -> G(3) = 1
    x = 4 -> G(4) = 2
    x = 5 -> G(5) = 0
    x = 6 -> G(6) = 0
    x = 7 -> G(7) = 1
    ...

    g = {0, 0, 1, 1, 2}

    
    */

    cout << (res ? "Rybka" : "Watson") << endl;
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