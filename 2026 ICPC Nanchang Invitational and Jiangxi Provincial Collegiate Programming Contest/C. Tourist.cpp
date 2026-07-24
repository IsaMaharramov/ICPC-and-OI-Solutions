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

int n, m, k, w, q;

struct Matrix
{
    int mat[1 << 8][1 << 8];

    Matrix()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                mat[i][j] = inf;
            }
        }
    }
};

Matrix multiply(const Matrix &A, const Matrix &B)
{
    Matrix C;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            int aik = A.mat[i][k];
            if (aik == inf)
                continue;

            for (int j = 0; j < n; ++j)
            {
                int bkj = B.mat[k][j];
                C.mat[i][j] = min(C.mat[i][j], max(aik, bkj));
            }
        }
    }
    return C;
}

Matrix qpow(Matrix a, int b)
{
    Matrix res = (--b, a);
    while (b > 0)
    {
        if (b & 1)
            res = multiply(res, a);
        b >>= 1;
        a = multiply(a, a);
    }
    return res;
}

void solve()
{
    cin >> n >> m;
    Matrix A;
    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        A.mat[u - 1][v - 1] = 0;
    }

    cin >> k;
    for (int i = 1, u, v; i <= k; ++i)
    {
        cin >> u >> v;
        --u, --v;
        A.mat[u][v] = min(A.mat[u][v], i);
    }

    cin >> q >> w;

    Matrix res = qpow(A, w);

    for (int i = 0, si, ti; i < q; ++i)
    {
        cin >> si >> ti;
        --si, --ti;
        if (res.mat[si][ti] == inf)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << res.mat[si][ti] << '\n';
        }
    }
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