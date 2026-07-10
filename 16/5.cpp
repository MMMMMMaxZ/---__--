#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	freopen("in.txt","r+",stdin);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	//reverse(a.begin(),a.end());
	for(int i=n-1;i>n-1-m;i--){
		cout<<a[i]<<' ';
	}
	return 0;
}

