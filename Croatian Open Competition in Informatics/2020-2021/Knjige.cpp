#include<bits/stdc++.h> //
using namespace std;
//#define int long long 
#define _rep(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
int q[101];
vector<string>res;
int l,r;
bool ll,rr;
void book(int maidx,int j)
{
	bool bl=false;
	_rep(i,0,j)
	if(i!=maidx)
		res.push_back("UZMI L L"),res.push_back("STAVI L D");
	else 
		res.push_back("UZMI D L");
	res.push_back("STAVI D L");
	_rep(i,0,j)
	if(i!=maidx)
		res.push_back("UZMI L D"),res.push_back("STAVI L L");
}
void solve()
{
	int n;
	cin>>n;
	_rep(i,0,n-1)
	cin>>q[i];
	for(int i=n-1;i>=1;i--){
		int maidx=0;
		for(int j=0;j<=i;j++)
			if(q[maidx]<=q[j])maidx=j;
		if(maidx!=i)
			book(maidx,i);
		int t=q[maidx];
		for(int j=maidx;j<i;j++)
			q[j]=q[j+1];
		q[i]=t;
		// for(int j=0;j<n;j++)
		// cout<<q[j]<<" ";
		// cout<<endl;
	}
	int t=res.size();
	cout<<t<<endl;
	for(int i=0;i<(int)res.size();i++)
		cout<<res[i]<<endl;
	
}
signed main()
{
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}