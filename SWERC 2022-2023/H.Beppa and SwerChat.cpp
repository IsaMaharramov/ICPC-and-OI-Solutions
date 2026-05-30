#include <iostream>
#include <map>
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (register int i = 1, d; i <= n; ++i)
        cin >> d, mp[d] = i;
    int a[n + 1];
    for (register int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int i = n;
    for (; i >= 1; --i)
    {
        if (mp[a[i]] < mp[a[i - 1]])
            break;
    }
    cout << max(i - 1, 0) << '\n';
    return;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        test_case();
    }
    exit(0);
}