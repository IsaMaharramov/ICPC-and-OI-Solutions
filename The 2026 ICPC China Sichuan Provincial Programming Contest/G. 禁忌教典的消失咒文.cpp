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

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    vector<int> sm(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i & 1)
            sm[i] = sm[i - 1] + a[i];
        else
            sm[i] = sm[i - 1] - a[i];
    }

    int tot = sm[n];

    vector<int> em;
    em.reserve(n + 1);
    for (int i = 0; i <= n; ++i)
        em.eb(sm[i]);
    sort(all(em));
    em.erase(unique(all(em)), em.end());
    int m = (int)em.size();

    auto get_id = [&](int x) -> int
    {
        auto it = lower_bound(all(em), x);
        if (it != em.end() && *it == x)
            return it - em.begin();
        return -1;
    };

    vector<int> cnt_e(m, 0), cnt_o(m, 0);

    int ans{0ll};

    for (int j = 1; j <= n; ++j)
    {
        int prev = get_id(sm[j - 1]);
        if ((j - 1) % 2 == 0)
            cnt_e[prev]++;
        else
            cnt_o[prev]++;

        int tp_e = sm[j] - (tot - k);
        int id_e = get_id(tp_e);
        if (id_e != -1)
        {
            if (j % 2 == 0)
                ans += cnt_e[id_e];
            else
                ans += cnt_o[id_e];
        }

        int tp_o = tot + k - sm[j];
        int id_o = get_id(tp_o);
        if (id_o != -1)
        {
            if (j % 2 == 0)
                ans += cnt_o[id_o];
            else
                ans += cnt_e[id_o];
        }
    }

    cout << ans << "\n";
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}