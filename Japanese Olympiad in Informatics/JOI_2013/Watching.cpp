#include<iostream>
#include<algorithm>

using namespace std;

int n, p, q;
const int MAX = 2001;
int dp[MAX][MAX];
int x[MAX];

int Find(int pos, int seg){
    int xpos = x[pos + 1] + seg - 1;
    int l = pos + 1, r = n - 1, mid, last = pos;
    while(l <= r){
            mid = l + ((r - l) >> 1);
            if(x[mid] <= xpos){
                last = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
    }
    return last;
}
bool check(int& w){
    dp[0][0] = -1;
    for(int i = 0; i <= p; ++i){
        for(int j = 0; j <= q; ++j){
                if(!i && !j) continue;
                if(!i) dp[i][j] = Find(dp[i][j-1], (w << 1));
                else if(!j) dp[i][j] = Find(dp[i-1][j], w);
                else dp[i][j] = max(Find(dp[i-1][j], w), Find(dp[i][j-1], (w << 1)));
                if(dp[i][j] == n - 1) return true;
        }
    }
    return false;
}
int solve(){
    cin >> n >> p >> q;
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    if(p + q >= n) return 1;
    sort(x, x + n);
    int l = 1, r = x[n-1], mid, w;
    while(l <= r){
        mid = l + ((r - l) >> 1);
        if(check(mid)){
            w = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return w;
}
int main(){
    ios_base::sync_with_stdio(false);
    cout << solve() << '\n';
    exit(0);
}
