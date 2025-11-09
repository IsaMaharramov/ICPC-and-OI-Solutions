#include "combo.h"
#include "bits/stdc++.h"

using namespace std;

char ch[] = "ABXY";

string guess_sequence(int N) {
    string x = "";
    x += ((press(x + "A" + x + "B") >= 1) ? ((press(x + "A") >= 1) ? "A": "B") : ((press(x + "X") >= 1) ? "X" : "Y"));
    vector<char> v;
    for(int i(0); i < 4; ++i) if(ch[i] ^ x[0]) v.emplace_back(ch[i]);
    for(int i(1); i < N - 1; ++i){
        int r{press(x + v[1] + x + v[2] + v[0] + x + v[2] + v[1] + x + v[2] + v[2])};
        x += ((r == i) ? v[0] : ((r == i + 1) ? v[1] : v[2]));
    }
    if(N > 1) x += (press(x + "A" + x + "B") >= N) ? ((press(x + "A") >= N) ? "A" : "B")  : ((press(x + "X") >= N) ? "X" : "Y");
    return x;
}