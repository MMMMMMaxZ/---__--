#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<set>
using namespace std;

const int INF = 1e6+2;

struct Node{
	int v;
	Node* nxt;
	Node(int v):v(v),nxt(nullptr){}
};

struct headNode{
	Node* e;
	headNode():e(nullptr){}
};

class Graph{
	headNode* edges;
	const int size;
	set<string> ans;
	public:
		Graph(int n):size(n+2){
			edges = new headNode[n+2];
		}
		void getEdge(int e){
			int u,v;
			for(int i=0;i<e;i++){
				cin>>u>>v;
				u--;v--;
				Node* newV = new Node(v);
				newV->nxt = edges[u].e;
				edges[u].e = newV;
			}
		}
		void search(int v,int x,bool vis[],vector<int> path){
			vis[x]=1;
			path.push_back(x);
			Node* p =edges[x].e;
			/*cout<<"?:";
			for(auto i:path)cout<<i;
			cout<<endl;*/
			if(x==v){
				ostringstream os;
				//sort(path.begin(),path.end());
				for(auto i:path)os<<i+1<<' ';
				ans.insert(os.str());
			}
			while(p!=nullptr){
				int tp = p->v;
				if(!vis[tp]){
					search(v,tp,vis,path);
				}
				p=p->nxt;
			}
			
			vis[x]=0;
		}
		void search(int s,int t){
			bool vis[size]={0};
			vector<int> path;
			search(t,s,vis,path);
			if(ans.empty()){
				cout<<"No Path\n";
				return;
			}
			for(auto i:ans){
				cout<<i<<endl;
			}
		}
};

int main(){
	int n,m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;s--;t--;
	Graph G(n);
	G.getEdge(m);
	G.search(s,t);
	
	return 0;
}

