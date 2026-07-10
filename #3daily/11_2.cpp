#include<iostream>
#include<unordered_set>
using namespace std;

const int N=1e4+2;

int main(){
	int n,x;
	unordered_set<int> nums;
	int a[N];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i--){
		nums.insert(a[i]);
	}
	for(auto i:nums){
		cout<< i <<' ';
	}
	return 0;
}

