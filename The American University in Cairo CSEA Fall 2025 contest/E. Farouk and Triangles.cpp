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

int a, b;

/*

d1 + d2 + d3 = h;

ah/2 = a*asin60 = sqrt(3)/4 * a^2

h = sqrt(3)/2 * a

d1 + d2 + d3 = sqrt(3)/2 * a

*/

int n, q, l[sz];

map<ld, int> mp;

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i];
        mp[l[i] / 2] = i;
    }
    ld sm = 0;
    while (q--)
    {
        sm = 0;
        for (int i = 0, d; i < 3; ++i)
        {
            cin >> d;
            sm += sqrtl(d / 3);
        }
        cout << (mp.count(sm) ? mp[sm] : -1) << '\n';
    }
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