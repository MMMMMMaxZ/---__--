#include<iostream>
#include<vector>
using namespace std;

int _hash[200];

int f(int k){
	return k%199;
}

int main(){
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	int x,a,n=0;
	cin>>x;
	while(cin>>a){
		n++;
		int h = f(a);
		while(_hash[h]!=0)h=(h+1)%200;
		_hash[h]=a;
	}
	vector<int> sch;
	int id = f(x);sch.push_back(_hash[id]);
	while(_hash[id]!=x){
		id=(id+1)%200;
		if(_hash[id]==0 or (int)sch.size()==n)break;
		sch.push_back(_hash[id]);
	}
	if(_hash[id]==x)cout<<"True\n";
	else cout<<"False\n";
	for(auto i:sch)
		cout<<i<<' ';
	
	return 0;
}

