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

void solve()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans * 10 + (s[i] - '0')) % 3;
    cout << (ans ? "no" : "yes") << endl;
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