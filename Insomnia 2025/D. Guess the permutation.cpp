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

constexpr int sz = 1e5 + 5;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << '\n';
}

int n, a[1 << 15];

int ask(array<int, 3> x)
{
    cout << "? " << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
    int res{0ll};
    cin >> res;
    return res;
}

void solve()
{
    cin >> n;
    array<int, 4> sm = {ask({1, 2, 3}), ask({1, 2, 4}), ask({1, 3, 4}), ask({2, 3, 4})};
    int x = (sm[0] + sm[1] + sm[2] + sm[3]) / 3;
    a[1] = x - sm[3];
    a[2] = x - sm[2];
    a[3] = x - sm[1];
    a[4] = x - sm[0];
    for (int i = 5; i <= n; ++i)
    {
        x = ask({1, 2, i});
        a[i] = x - a[1] - a[2];
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << endl;
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