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
#define endl '\n'

using namespace std;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int sz = 1e6 + 5;
constexpr int mod = 1e9 + 7;
// constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << endl;
}

int p[sz];

void precomp()
{
    for (int i = 1; i < sz; ++i)
        p[i] = i;
    for (int i = 2; i * i < sz; ++i)
    {
        if (p[i] ^ i)
            continue;
        for (int j = i * i; j < sz; j += i)
            if (p[j] == j)
                p[j] = i;
    }
    return;
}

bool cmp(int x, int y)
{
    if (x == 1)
        return y ^ 1;
    if (y == 1)
        return false;
    while (min(x, y) > 1)
    {
        if (p[x] ^ p[y])
            return p[x] < p[y];
        x /= (y /= p[y], p[x]);
    }
    return (x == 1 && y > 1);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    precomp();
    vector<int> em(n);
    iota(all(em), 1);
    sort(all(em), cmp);
    for (int qr = 1, k; qr <= q; ++qr)
        cout << (cin >> k, em[k - 1]) << '\n';
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