#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1e5 + 5, inf = 1e9 + 7;

int n, m, tot, sizel[sz], timel[sz], fa[sz], tag[sz];

int find_set(int v)
{
    while (fa[v] ^ v)
        v = fa[v];
    return v;
}

inline void Union(int a, int b, int t)
{

    a = find_set(a);
    b = find_set(b);

    if (a ^ b)
    {
        if (sizel[a] > sizel[b])
            swap(a, b);

        sizel[b] += sizel[a];
        fa[a] = fa[b];

        timel[a] = t;
    }
    return;
}

inline void init()
{
    tot = 0;
    for (register int i = 1; i <= n; ++i)
        fa[i] = i, sizel[i] = 1, timel[i] = inf, tag[i] = 0;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT;
    cin >> TT;
    function<void()> test_case = [&]()
    {
        cin >> n >> m;
        init();

        for (register int i = 1, type, a, b; i <= m; ++i)
        {
            cin >> type >> a >> b;
            if (type == 1)
            {
                Union(a, b, i);
            }
            else
            {
                if (find_set(a) ^ find_set(b))
                {
                    cout << -1 << '\n';
                    continue;
                }
                int x, lca{-1};
                ++tot;
                for (x = a; x != fa[x]; x = fa[x])
                    tag[x] = tot;
                for (x = b; x != fa[x]; x = fa[x])
                    if (tag[x] == tot)
                        break;
                lca = x;
                int ans(0);
                for (; a != lca; a = fa[a])
                    ans = max(ans, timel[a]);
                for (; b != lca; b = fa[b])
                    ans = max(ans, timel[b]);

                cout << ans << '\n';
            }
        }
    };
    while (TT--)
        test_case();
    return 0;
}