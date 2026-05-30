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

constexpr int sz = 1e5 + 5;
constexpr int mod = 998244353;
constexpr int inf = 1e18 + 7;

void show(vector<int> &v)
{
    for (auto &to : v)
        cout << to << ' ';
    cout << endl;
}

int a[sz];

void solve()
{
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    int res = 0ll;
    for(int i = 1; i <= M; ++i){
        if(i > N) break;
        int dp_p0 = 0ll, dp_p1 = 0ll;
        for(int j = i + M; j <= N; j += M){

            int psum = a[j] + a[j - M]; 

            int dp_cur0 = max(dp_p1, dp_p0);
            int dp_cur1 = dp_p0 + psum;

            dp_p0 = dp_cur0;
            dp_p1 = dp_cur1;
        }

        res += max(dp_p0, dp_p1);
    }
    cout << res << endl;
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