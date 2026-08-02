#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

constexpr int sz = 1e6 + 6;
constexpr int mod = 1e9 + 7;
constexpr int inf = 1e9 + 7;

void solve()
{
    int h, w;
    cin >> h >> w;
    if (w >= 2 * h + 1)
    {
        cout << "Yes" << '\n';
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                if ((max(i, j) == 1) or (i == h and j == w))
                {
                    cout << '.';
                }
                else if (j % 2 == 0)
                {
                    if ((j % 4 == 2 and i & 1) or (j % 4 == 0 and i % 2 == 0))
                        cout << 'X';
                    else
                        cout << '.';
                }
                else
                {
                    cout << '.';
                }
            }
            cout << '\n';
        }
    }
    else if (h >= 2 * w + 1)
    {
        cout << "Yes" << '\n';
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                if ((max(i, j) == 1) or (i == h and j == w))
                {
                    cout << '.';
                }
                else if (i % 2 == 0)
                {
                    if ((i % 4 == 2 and j & 1) or (i % 4 == 0 and j % 2 == 0))
                        cout << 'X';
                    else
                        cout << '.';
                }
                else
                {
                    cout << '.';
                }
            }
            cout << '\n';
        }
    }
    else
    {
        cout << "No" << '\n';
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