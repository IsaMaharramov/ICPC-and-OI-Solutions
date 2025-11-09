#include<bits/stdc++.h>
using namespace std;

int n, l[1000100], r[1000100];

string z;

int ans[1000100];

set<pair<int, int>> pq;

set<int> st;

vector<int> tmp;

vector<pair<int, int>> v;

inline bool makni(int pos){
	
	auto it = st.lower_bound(pos);
	
	if(it == st.end()) return 0;
	
	st.erase(it);
	
	return 1;
	
}


signed main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	function<void()> test_case = [](){
		cin >> n >> z;
		
		z = '.' + z;
		
		st.clear(), pq.clear(), v.clear(), tmp.clear();
		
		for(register int i = 1; i <= n; ++i){
			cin >> l[i] >> r[i];
			
			if(z[l[i]] == '(' && z[r[i]] == '('){
				tmp.emplace_back(l[i]);
				
				ans[i] = 0;
				
				
			}else if(z[l[i]] == ')' && z[r[i]] == ')'){
				st.insert(r[i]);
				
				ans[i] = 1;
				
			}else if(z[l[i]] == '(' && z[r[i]] == ')'){
				st.insert(r[i]);
				
				v.emplace_back(pair<int, int>{l[i], i});
				
				ans[i] = 1;
				
			}else{
				
				st.insert(l[i]);
				
				v.emplace_back(pair<int, int>{l[i], i});
				
				ans[i] = 0;
				
			}
			
			
			
			
		}
		
	//	if(n & 1) return cout << -1 << '\n', void();
		
		for(auto to : tmp){
			
			if(!makni(to)) return cout << -1 << '\n', void();
			
			
		}
		
		
		sort(v.begin(), v.end());
		
		int p = -1;
		
		while(!st.empty()){
			int lim = *st.begin();
			
			while(p + 1 < (int)v.size() && v[p+1].first <= lim){
				p++;
				
				int ind = v[p].second;
				
				pq.insert({r[ind], ind});
				
			}
			
			if(pq.empty()) return cout << -1 << '\n', void();
			
			int ind = pq.begin()->second;
			
			pq.erase(pq.begin());
			
			ans[ind] ^= 1;
			
			if(!makni(l[ind])) return cout << -1 << '\n', void();
			
			if(!makni(r[ind])) return cout << -1 << '\n', void();
			
			
		}
		

		for(register int i = 1; i <= n; ++i){
			 cout << ans[i] << " \n"[i==n];
		}
		
		
		
		
		
	};
	while(T--) test_case();
	return 0;
}