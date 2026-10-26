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
#define ll long long
// #define endl '\n'
#define ok puts("ok")

using namespace std;
using ld = long double;
using vi = vector<int>;
using vii = vector<pii>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int sz = 2e5 + 5;
constexpr int mod = 998244353;
// constexpr int inf = 1e18 + 7;

void show(vi &a)
{
    for (auto &to : a)
        cout << to << ' ';
    cout << endl;
    return;
}

int n, m;

char c[1 << 7][1 << 7];
array<int, 4> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            c[i][j] = '?';
        }
    }
    auto ask = [&](int x, int y)
    {
        cout << "? " << x + 1 << ' ' << y + 1 << endl;
        char ch;
        cin >> ch;
        return ch;
    };

    for (int x = 1; x < n; x += 2)
    {
        for (int y = 1; y < m; y += 2)
        {

            c[x][y] = ask(x, y);

            if (c[x][y] == 'U')
            {
                c[x + 1][y] = 'D';
            }
            else if (c[x][y] == 'L')
            {
                c[x][y + 1] = 'R';
            }
            else if (c[x][y] == 'D')
            {
                c[x - 1][y] = 'U';
            }
            else if (c[x][y] == 'R')
            {
                c[x][y - 1] = 'L';
            }
        }
    }

    auto geht = [&](int x, int y)
    {
        vii res;
        for (int i = 0; i < 4; ++i)
        {
            int tox = x + dx[i], toy = y + dy[i];
            if (tox < 0 || tox >= n || toy < 0 || toy >= m || c[tox][toy] != '?')
                continue;
            res.eb(pii{tox, toy});
        }
        return res;
    };

    queue<pii> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (c[i][j] == '?' and (int) geht(i, j).size() == 1)
                q.push(pii{i, j});
        }
    }

    while (!q.empty())
    {
        pii cur = q.front();
        int x = cur.F, y = cur.S;
        q.pop();

        if (c[x][y] != '?')
            continue;

        auto woo = geht(x, y);
        if ((int)woo.size() ^ 1)
            continue;

        int tox = woo[0].F, toy = woo[0].S;

        if (tox == x + 1)
        {
            c[x][y] = 'U';
            c[tox][toy] = 'D';
        }
        else if (tox == x - 1)
        {
            c[x][y] = 'D';
            c[tox][toy] = 'U';
        }
        else if (toy == y + 1)
        {
            c[x][y] = 'L';
            c[tox][toy] = 'R';
        }
        else if (toy == y - 1)
        {
            c[x][y] = 'R';
            c[tox][toy] = 'L';
        }

        auto check = [&](int cx, int cy)
        {
            for (int k = 0; k < 4; ++k)
            {
                int wx = cx + dx[k], wy = cy + dy[k];
                if (wx < 0 || wx >= n || wy < 0 || wy >= m || c[wx][wy] != '?')
                    continue;
                if ((int)geht(wx, wy).size() == 1)
                    q.push(pii{wx, wy});
            }
        };
        check(x, y);
        check(tox, toy);
    }

    cout << "!\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << c[i][j];
        }
        cout << '\n';
    }
    cout << endl;
    return;
}

signed main()
{
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}