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
constexpr int inf = 1e18; //+ 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << '\n';
}

char y;

char ask(int x)
{
    cout << "? " << x << endl;
    cin >> y;
    return y;
}

void solve()
{
    char col_cur = ask(0);
    int cur = 0, nxt = 0;
    char col_nxt = col_cur;
    nxt = cur + 1;
    bool flag = false;

    while (true)
    {
        col_nxt = ask(nxt);
        if (col_nxt != col_cur)
        {
            break;
        }
        if (nxt == inf)
            break;
        nxt = min(inf, nxt * 2);
    }

    if (col_cur == col_nxt)
    {
        flag = 1;
        nxt = 0;
        cur = nxt - 1;

        while (true)
        {
            col_cur = ask(cur);
            if (col_cur != col_nxt)
            {
                break;
            }
            if (cur == -inf)
            {
                assert(0);
                break;
            }
            cur = max(cur * 2, -inf);
        }
    }

    int l, r, mid, best, res = 0;
    if (flag)
    {
        l = cur, r = 0, mid, best = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (ask(mid) == col_cur)
            {
                best = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        ++best; // transition
    }
    else
    {
        l = 0, r = nxt, mid, best = nxt;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (ask(mid) == col_nxt)
            {
                best = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }

    // check
    int dir;
    if (best > 0)
    {
        best--;
        dir = -1;
    }
    else
    {
        dir = 1;
    }

    char tbcol = ask(best);
    // int dir{(best > 0 ? -1 : 1)};

    int d_prev(0), d_cur(1);
    while (1)
    {
        if (ask(best + dir * d_cur) != tbcol)
            break;
        d_cur = (d_prev = d_cur, d_cur * 2);
    }

    res = d_cur;
    l = d_prev + 1, r = d_cur;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (ask(best + dir * mid) != tbcol)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    // res--;
    cout << "! " << res << endl;
}

signed main()
{
    //    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}