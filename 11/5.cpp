#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class grath{
	vector<vector<int>> e;
	int* vis;
	int fdType;
	public:
		grath(int size){
			vis = new int[size];
			for(int i=0;i<size;i++){
				vis[i]=0;
				e.emplace_back();
			}
			fdType = 0;
		}
		void ini(){
			int sz = e.size();
			for(int i=0;i<sz;i++)vis[i]=0;
		}
		void addEdge(int x,int y){
			e[x].push_back(y);
		}
		void find(int x){
			if(vis[x]!=0)return;
			vis[x]=fdType;
			if(e[x].empty())return ;
			for(auto i:e[x])find(i);
		}
		int getF(){
			fdType = 1;
			int sz = e.size();
			ini();
			for(int i=0;i<sz;i++){
				if(vis[i]!=0)continue;
				find(i);
				fdType++;
			}
			return fdType-1;
		}
		
};

int main(){
	int n,m;
	cin>>n>>m;
	grath g(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x-1,y-1);
		g.addEdge(y-1,x-1);
	}
	int ans = g.getF();
	if(ans==1){
		cout<<"YES";
	}else{
		cout<<"NO "<<ans;
	}
	
	
	return 0;
}

