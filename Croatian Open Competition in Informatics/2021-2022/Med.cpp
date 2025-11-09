#include<bits/stdc++.h>
using namespace std;

int n;

int sm[501];
string s[501];

vector<pair<int, string>> em;

pair<int, int> get(int i){
	
	em.clear();
	
	pair<int, int> res;
	
	for(register int j = 1; j <= n; ++j){
		em.emplace_back(pair<int, string>{sm[j] + (i!=j?-500:0), s[j]});
	}
	
		
	sort(em.begin(), em.end());
		
	res.first = distance(em.begin(), find(em.begin(), em.end(), pair<int, string>{sm[i], s[i]})) + 1;
	
	em.clear();
	
	for(register int j = 1; j <= n; ++j){
		em.emplace_back(pair<int, string>{sm[j] + (i==j?-500:0), s[j]});
	}
	
		
	sort(em.begin(), em.end());
		
	res.second = distance(em.begin(), find(em.begin(), em.end(), pair<int, string>{sm[i] - 500, s[i]})) + 1;
	
	
	return res;
}

signed main(){
	cin >> n;
	for(register int i = 1; i <= n; ++i){
		cin >> s[i];
		for(register int j = 1, a; j <= 5; ++j){
			cin >> a;
			sm[i] += a;
		}
		sm[i] *= -1;
	}
	
	for(register int i = 1; i <= n; ++i){
		
		pair<int, int> ou = get(i);
		
		cout << ou.second <<  ' ' << ou.first << '\n';
		
	}
	
	return 0;
}