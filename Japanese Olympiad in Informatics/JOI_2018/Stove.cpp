#include<iostream>
#include<random>
#include<chrono>
#include<vector>
#include<algorithm>
#define oo 1000000001
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int sz = 1e5 + 3;
ll T[sz];
int n, k;
int main(){
    cin.tie()->sync_with_stdio(false);
    cin >> n >> k;
    vector<ll> dif;
    cin >> T[1];
    for(register int i = 2; i <= n; ++i){
        cin >> T[i];
        dif.emplace_back(T[i] - T[i-1]);
    }
    if(n <= k){
        cout << n << '\n';
        exit(0);
    }
    sort(all(dif));
    ll ans(0);
    for(register int i = 0; i < n - k; ++i) ans += dif[i];
    cout << ans + k << '\n';


    exit(0);
}
