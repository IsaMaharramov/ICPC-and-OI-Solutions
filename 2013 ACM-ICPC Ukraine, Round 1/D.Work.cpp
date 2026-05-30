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

constexpr int sz = 3e4 + 5;
constexpr int mod = 998244353;
constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << endl;
}

int l[sz], r[sz]; 
bitset<sz> is_prime;

void solve()
{
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;

    for(int i = 2; i < sz; ++i){
        is_prime[i] = 1;
    }

    for(int i = 2; i * i < sz; ++i){
        if(is_prime[i]){
            for(int j = i * i; j < sz; j += i){
                is_prime[j] = 0;
            }
        }
    }

    int res = 0;

    string tot = "";
    for(int i = 1; i <= N; ++i){
        tot += (is_prime[i] ? 'Y' : 'N');
    }

    int j = 0;
    for(int i = 0; i < M; ++i){
        while(j <= N and (tot[j] ^ s[i])) ++j;
        l[i] = j++;
    }

    j = N - 1;
    for(int i = M - 1; i >= 0; --i){
        while(j >= 0 and (tot[j] ^ s[i])) --j;
        r[i] = j--;
    }

    for(int i = 0; i < M; ++i){
        res += l[i] == r[i];
    }
    cout<< res << endl;
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