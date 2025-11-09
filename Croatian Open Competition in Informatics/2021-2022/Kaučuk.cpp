#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,fma")
#include<bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	string type, name;
	int sec(0), subsec(0), subsubsec(0);
	for(register int i = 0; i < N; ++i){
		cin >> type >> name;
		if(type == "section"){
			subsec = subsubsec = 0;
			++sec;
			cout << sec << ' ' << name << '\n';
		}else if(type == "subsection"){
			subsubsec = 0;
			++subsec;
			cout << sec << '.' << subsec << ' ' << name << '\n';
		}else{
			++subsubsec;
			cout << sec << '.' << subsec << '.' << subsubsec << ' ' << name << '\n';
		}
    }
    return 0;
}