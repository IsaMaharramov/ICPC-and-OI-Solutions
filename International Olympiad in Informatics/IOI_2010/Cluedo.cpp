#include "grader.h"
#include "cluedo.h"
#include<bits/stdc++.h>
using namespace std;

//
//static int M,L,W,gotit,cnt,maxcnt;
//
//int Theory(int m, int l, int w) {
//   ++cnt;
//   if (m < 1 || m > 6 || l < 1 || l > 10 || w < 1 || w > 6) exit(92);
//   if (rand()%2 && m != M) return 1;
//   else if (rand()%2 && l != L) return 2;
//   else if (rand()%2 && w != W) return 3;
//   else if (m != M) return 1;
//   else if (l != L) return 2;
//   else if (w != W) return 3;
//   gotit = 1;
//   return 0;
//}

void Solve(){
	
	int a = 1, b = 1, c = 1;
	
	while(true){
		
		int ou = Theory(a, b, c);
		
		if(ou == 0) return;
		if(ou == 1) ++a;
		if(ou == 2) ++b;
		if(ou == 3) ++c;
		
	}
	
}

//
//signed main(){
//	cin >> M >> L >> W;
//	Solve();
//	return 0;
//}