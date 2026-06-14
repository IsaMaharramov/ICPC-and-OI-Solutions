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

int n;
string s;

int cnt[2][26];

void solve()
{

    cin >> s;
    n = (int)s.size();
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; ++i)
        cnt[(i + 1) & 1][s[i] - 'a']++;

    bool flag{true};
    if (n & 1)
    {
        int mid = ((n + 1) / 2) & 1;
        for (int i = 0; i < 26 and flag; ++i)
            flag &= !(cnt[1 ^ mid][i] & 1);
        if (flag)
        {
            int x(0);
            for (int i = 0; i < 26; ++i)
                x += (cnt[mid][i] & 1);
            flag &= (x == 1);
        }
    }
    else
    {
        for (int i = 0; i < 26; ++i)
            flag &= (cnt[0][i] == cnt[1][i]);
    }
    puts(flag ? "YES" : "NO");
    return;
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