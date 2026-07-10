#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;

int main(){
	int n,m,sum=0;
	int a[2*N];
	cin>>n>>m;
	for(int i=0;i<n+m+1;i++){
		cin>>a[i];
	}
	sort(a,a+n+m+1);
	for(int i=0;i<m;i++){
		sum-=a[i];
	}
	for(int i=m;i<n+m+1;i++){
		sum+=a[i];
	}
	cout<<sum;
	
	return 0;
}

