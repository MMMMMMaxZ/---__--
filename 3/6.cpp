#include<bits/stdc++.h>
using namespace std;

const int N=33000,INF=2e6+2;
int n;
int a[N];
int ans=0;

int main(){
	cin>>n;
	cin>>a[0];
	ans+=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		int mn=INF;
		for(int j=0;j<i;j++){
			mn=min(mn,abs(a[i]-a[j]));
		}
		ans+=mn;
	}
	cout<<ans<<endl;
	
	return 0;
}

