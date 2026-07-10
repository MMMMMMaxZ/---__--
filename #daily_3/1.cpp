#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(vector<int> &a,int i,vector<vector<int>> &vc,vector<int> &fs,bool vis[]){
	vis[i]=true;
	a.push_back(i);
	for(auto j=vc[i].rbegin();j!=vc[i].rend();j++){
		int x = *j;
		fs[x]--;
		if(fs[x]==0)DFS(a,x,vc,fs,vis);
	}
}

int main(){
	vector<vector<int>> vc;
	vector<int> fs;
	int n,m;
	cin>>n>>m;
	vc.resize(n);
	fs.resize(n);
	bool vis[n]={0};
	for(int i=0;i<n;i++)fs[i]=0;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		vc[u].push_back(v);
		fs[v]++;
	}
	vector<int> a;
	for(int i=0;i<n;i++){
		if(fs[i]==0 and vis[i]==false){
			DFS(a,i,vc,fs,vis);
		}
	}
	if((int)a.size()!=n){
		cout<<-1;
		return 0;
	}else{
		for(auto i:a){
			cout<<i<<' ';
		}
	}
	
	return 0;
}

