#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(vector<int> &a,int i,vector<vector<int>> &vc,bool vis[]){
	vis[i]=true;
	for(auto x:vc[i]){
		if(not vis[x])DFS(a,x,vc,vis);
	}
	a.push_back(i);
}

int main(){
	vector<vector<int>> vc;
	int n,m;
	cin>>n>>m;
	vc.resize(n);
	int fs[n]={0};
	bool vis[n]={0};
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		vc[u].push_back(v);
		fs[v]++;
	}
	vector<int> a;
	for(int i=0;i<n;i++){
		if(fs[i]==0 and vis[i]==false){
			DFS(a,i,vc,vis);
		}
	}
	if((int)a.size()!=n){
		cout<<-1;
		return 0;
	}else{
		reverse(a.begin(),a.end());
		for(auto i:a){
			cout<<i<<' ';
		}
	}
	
	return 0;
}

