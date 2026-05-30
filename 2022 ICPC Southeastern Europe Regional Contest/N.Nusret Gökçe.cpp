#include <bits/stdc++.h>
using namespace std;

int n, m, s[100010];

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (register int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    /*
    si >= si+1 - m
    si >= si-1 - m
    */

    for (register int i = 2; i <= n; ++i)
    {
        s[i] = max(s[i], s[i - 1] - m);
    }

    for (register int i = n - 1; i >= 1; --i)
    {
        s[i] = max(s[i], s[i + 1] - m);
    }

    for (register int i = 1; i <= n; ++i)
    {
        cout << s[i] << " \n"[i == n];
    }

    return 0;
}