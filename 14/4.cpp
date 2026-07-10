#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k,x;
	vector<int> a;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	int l = 0, r = n - 1,cnt=0;
	
	while (l < r) {
		cnt++;
	    int mid = (l + r) / 2;
	    //cout<<l<<' '<<r<<' '<<mid<<endl;
	    if (a[mid]<k) l = mid + 1;
	    else r = mid;
	}
	if(a[r]==k)cout<<cnt;
	else cout<<-1;
	return 0;
}

