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
constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << '\n';
}

struct BigInt
{
    std::vector<int> digits;

    BigInt() { digits = {0}; }
    BigInt(long long v)
    {
        if (v == 0)
            digits = {0};
        while (v > 0)
        {
            digits.push_back(v % 10);
            v /= 10;
        }
    }

    void multiply(int x)
    {
        long long carry = 0;
        for (size_t i = 0; i < digits.size(); ++i)
        {
            long long cur = digits[i] * 1LL * x + carry;
            digits[i] = cur % 10;
            carry = cur / 10;
        }
        while (carry > 0)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    BigInt multiply(const BigInt &other) const
    {
        BigInt result;
        result.digits.assign(digits.size() + other.digits.size(), 0);
        for (size_t i = 0; i < digits.size(); ++i)
        {
            long long carry = 0;
            for (size_t j = 0; j < other.digits.size(); ++j)
            {
                long long cur = result.digits[i + j] + digits[i] * 1LL * other.digits[j] + carry;
                result.digits[i + j] = cur % 10;
                carry = cur / 10;
            }
            if (carry > 0)
            {
                result.digits[i + other.digits.size()] += carry;
            }
        }
        while (result.digits.size() > 1 && result.digits.back() == 0)
        {
            result.digits.pop_back();
        }
        return result;
    }

    void add(const BigInt &other)
    {
        size_t n = std::max(digits.size(), other.digits.size());
        long long carry = 0;
        for (size_t i = 0; i < n || carry; ++i)
        {
            if (i == digits.size())
                digits.push_back(0);
            long long sum = digits[i] + carry + (i < other.digits.size() ? other.digits[i] : 0);
            digits[i] = sum % 10;
            carry = sum / 10;
        }
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<BigInt> fact(n + 1);
    fact[0] = BigInt(1);

    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1], fact[i].multiply(i);

    BigInt tot(0);

    for (int i = 0; i <= n; ++i)
    {
        BigInt x(1);
        for (int p = 0; p < k; ++p)
            x = x.multiply(fact[i]);
        tot.add(x);
    }

    int res = 0;
    for (int &to : tot.digits)
    {
        if (to != 0)
        {
            res = to;
            break;
        }
    }
    cout << res << '\n';
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