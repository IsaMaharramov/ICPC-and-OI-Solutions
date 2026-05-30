#include "bits/stdc++.h"
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define oo 1000000001
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define y1 y_1
#define int long long
#define endl '\n'

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
    cout << endl;
}

void solve()
{
    int N, A, B;
    cin >> N >> A >> B;
    function<int(int)> get_sm = [&](int a){
        if(a >= N) return 0ll;
        int k = (N - 1) / a;
        k %= mod;
        a %= mod;
        k = (k * (k + 1) / 2) % mod;
        return (k * a) % mod;
    };
    int sma = get_sm(A);
    int smb = get_sm(B);
    int g = __gcd(A, B), smab{0ll};
    if(A / g <= (N - 1) / B) smab = get_sm((A / g) * B);
    cout << (sma + smb - smab + mod) % mod << endl;
    return;
}

signed main()
{
    SPEED;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}