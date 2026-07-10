#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	freopen("in.txt","r+",stdin);
	int n,t=0;
	cin>>n;
	vector<pair<int,int>> a;
	vector<vector<pair<int,int>>> x(n,vector<pair<int,int>>());
	for(int i=0;i<n;i++){
		int l,w;
		cin>>l>>w;
		a.push_back(make_pair(l,w));
	}
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	sort(a.begin(),a.end());
	x[t++].push_back(a[0]);
	for(int i=1;i<n;i++){
		auto tp = a[i];
		bool find=false;
		for(int j=0;j<t;j++){
			int k=0;
			auto xp2 = x[j][k];
			if(tp.first<=xp2.first and tp.second<=xp2.second){
				x[j].insert(x[j].begin(),tp);
				find=true;
				break;
			}
			for(k=0;k<(int)x[j].size()-1;k++){
				auto xp = x[j][k];
				auto xp2 = x[j][k+1];
				if((tp.first<=xp2.first and tp.second<=xp2.second)and(xp.first<=tp.first and xp.second<=tp.second)){
					x[j].insert(x[j].begin()+k+1,tp);
					find=true;
					break;
				}
			}
			if(find)break;
			auto xp = x[j][(int)x[j].size()-1];
			if(xp.first<=tp.first and xp.second<=tp.second){
				x[j].push_back(tp);
				find = true;
				break;
			}
		}
		if(not find){
			x[t++].push_back(tp);
		}
	}
	/*for(int i=0;i<t;i++){
		for(auto j:x[i]){
			cout<<(j.first)<<','<<(j.second)<<' ';
		}
		cout<<endl;
	}*/
	cout<<t<<endl;
	
	return 0;
}

