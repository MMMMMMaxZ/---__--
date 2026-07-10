#include<iostream>
#include<set>
using namespace std;

const int N=1e4+5;
set<int> s;
int n,m;
int x;

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		s.insert(x);
	}
	for(int i=0;i<m;i++){
		cin>>x;
		s.insert(x);
	}
	for(auto i=s.begin();i!=s.end();i++)
		cout<<*i<<' ';
	
	return 0;
}

