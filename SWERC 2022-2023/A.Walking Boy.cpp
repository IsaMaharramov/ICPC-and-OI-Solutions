#include <iostream>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    auto test_case = [&]() { ///->:)
        int n;
        cin >> n;
        int a, b;
        cin >> a;
        int start = a;
        int ans(0);
        for (register int i = 2; i <= n; ++i)
        {
            cin >> b;
            if ((120 <= b - a) && (b <= 1440))
                ans += (b - a) / 120;
            a = b;
        }
        if (a < 1440)
        {
            ans += (1440 - a) / 120;
        }
        if (start >= 120)
        {
            ans += start / 120;
        }
        if (ans >= 2)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
        return;
    };
    while (T--)
    {
        test_case();
    }
    exit(0);
}