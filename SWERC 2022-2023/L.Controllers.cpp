#include <iostream>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n;
    string s;
    cin >> s;
    int m(0), p(0);
    for (register int i = 0; i < n; ++i)
    {
        m += (s[i] == '-');
        p += (s[i] == '+');
    }
    cin >> q;
    int tot = p - m, x, y;
    while (q--)
    {
        cin >> x >> y;
        if (!tot)
        {
            cout << "YES" << '\n';
            continue;
        }
        if (x == y)
        {
            cout << "NO" << '\n';
            continue;
        }
        if (((1ll * y * tot) % (y - x)) == 0 && ((1ll * y * tot) / (y - x)) >= -m && ((1ll * y * tot) / (y - x)) <= p)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    exit(0);
}