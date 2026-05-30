#include <iostream>
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    int a = 1;
    for (register int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            a = n / i;
            break;
        }
    }
    cout << a << ' ' << n - a << '\n';
}
int main()
{
    cin.tie()->sync_with_stdio();
    int T;
    cin >> T;
    while (T--)
    {
        test_case();
    }
    exit(0);
}