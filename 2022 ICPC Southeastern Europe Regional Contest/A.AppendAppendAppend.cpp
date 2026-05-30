#include <bits/stdc++.h>
using namespace std;
string a, b;
vector<int> in[27];
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    const int n = (int)a.size(), m = (int)b.size();
    for (register int i = 0; i < n; ++i)
    {
        in[a[i] - 'a'].emplace_back(i);
    }
    for (register int i = 0; i < 26; ++i)
    {
        in[i].emplace_back(n);
    }
    int l(0), ans(0);
    while (l < m)
    {
        ++ans;
        for (register int i = 0; i < n && l < m;)
        {
            i = *lower_bound(in[b[l] - 'a'].begin(), in[b[l] - 'a'].end(), i);
            if (i == n)
                break;
            ++l, ++i;
        }
    }
    cout << ans << '\n';
    return 0;
}