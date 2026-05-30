#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<unsigned long long> a(N, 0);
    unsigned long long sm(0);
    for (register int i = 0; i < N; ++i)
    {
        cin >> a[i];
        sm += a[i];
    }
    unsigned long long mx = *max_element(a.begin(), a.end());
    unsigned long long ans = min(sm / 3, sm - mx);
    cout << ans << '\n';
    return 0;
}