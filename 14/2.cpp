#include<iostream>
using namespace std;

int main(){
	bool flag = false;
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(i==a)flag=true;
	}
	if(flag)cout<<"Yes";
	else cout<<"No";
	return 0;
}

