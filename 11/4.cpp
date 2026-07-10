#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
5
0 1 0 1 0
0 0 1 1 0
0 0 0 1 1
0 0 0 0 0
1 0 0 1 0
0
*/

class grath{
	vector<vector<int>> e;
	bool* vis;
	public:
		grath(int size){
			vis = new bool[size];
			for(int i=0;i<size;i++){
				vis[i]=0;
				e.emplace_back();
			}
		}
		void ini(){
			int sz = e.size();
			for(int i=0;i<sz;i++)vis[i]=0;
		}
		void addEdge(int x,int y){
			e[x].push_back(y);
		}
		void find(int x){
			if(vis[x])return;
			cout<<x<<' ';
			vis[x]=1;
			if(e[x].empty())return ;
			for(auto i:e[x])find(i);
		}
		void find_stk(int x){
			stack<int> stk;
			stk.push(x);
			while(not stk.empty()){
				int tp = stk.top();stk.pop();
				if(vis[tp])continue;
				cout<<tp<<' ';
				vis[tp]=1;
				for(auto i=e[tp].rbegin();i!=e[tp].rend();i++){
					stk.push(*i);
				}
				
			}
		}
};

int main(){
	int n;
	cin>>n;
	grath g(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			bool k;
			cin>>k;
			if(k)g.addEdge(i,j);
		}
	}
	int x;
	cin>>x;
	g.ini();
	g.find_stk(x);
	cout<<endl;
	g.ini();
	g.find(x);
	return 0;
}

