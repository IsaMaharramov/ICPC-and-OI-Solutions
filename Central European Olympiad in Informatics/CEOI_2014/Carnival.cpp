
#include<iostream>

using namespace std;


int  n, color;


int c[200], cn[200];


int main(){
	cin>>n;
	++color, c[1]=color, cn[1]=1;
	for(int i=2; i<=n; ++i){
		cout<<i<<' ';
		for(int j=1; j<=i; ++j){
			cout<<j<<' ';
		}
		cout<<endl;
		cin>>cn[i];
		if(cn[i] ^ cn[i-1]){
			c[i]=++color;
			continue;
		}
		
		
		
		int l=1, r=i-1, mid, best, cnt;
		
		while(l<=r){
			mid=l+((r-l)>>1);
			cout<<mid+1<<' ';
			for(int k=1; k<=mid; ++k){
				cout<<k<<' ';
			}
			cout<<i<<endl;
			cin>>cnt;
			if(cnt == cn[mid]){
				r=mid-1;
				best=mid;
			}else{
				l=mid+1;
			}		
			
		}
		c[i]=c[best];
			
	}
	
	for(int i=0; i<=n; ++i){
		cout<<c[i]<<' ';
	}
	cout<<endl;
	
	return 0;
}


