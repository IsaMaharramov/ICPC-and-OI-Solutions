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
    int n = (cin >> n, n);
    string s, t;
    function<int(int)> ispalindrome = [&](int x)
    {
        int rx = 0, y = x;
        while (y)
        {
            rx = rx * 10 + y % 10;
            y /= 10;
        }
        return rx == x;
    };
    array<int, 3> a = {-1, -1, -1};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            int x = i * j;
            if (ispalindrome(x))
            {
                if (a[2] > x)
                    continue;
                if(j > a[0] and x == a[2]) continue;
                a[0] = j;
                a[1] = i;
                a[2] = x;
            }
        }
    }
    cout << a[0] << ' ' << a[1] << endl;
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