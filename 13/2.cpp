#include<iostream>
#include<queue>
using namespace std;

const int INF = 1e6+2;

struct Node{
	int v;
	int w;
	Node* nxt;
	Node(int v,int w):v(v),w(w),nxt(nullptr){}
};

struct headNode{
	Node* e;
	headNode():e(nullptr){}
};

class Graph{
	headNode* edges;
	const int size;
	public:
		Graph(int n):size(n+2){
			edges = new headNode[n+2];
		}
		void getEdge(int e){
			int u,v,w;
			for(int i=0;i<e;i++){
				cin>>u>>v>>w;
				Node* newV = new Node(v,0-w);
				newV->nxt = edges[u].e;
				edges[u].e = newV;
			}
		}
		int getSecondShortest(int s,int t){
			bool getFirstShortcut = false;
			int firstShort = INF;
			priority_queue<pair<int,int>> p;
			p.push({0,s});
			while(!p.empty()){
				pair<int,int> tp = p.top();p.pop();
				int stp = tp.first,si = tp.second;
				if(si==t){
					if(getFirstShortcut)
						if(0-stp > firstShort)return 0-stp;
						else continue;
					else{
						getFirstShortcut=1;
						firstShort = 0-stp;
					}
				}
				Node* q = edges[si].e;
				while(q!=nullptr){
					p.push({stp+(q->w),q->v});
					q=q->nxt;
				}
			}
			return -1;
		}
};

int main(){
	int V,E,s,t;
	cin>>V>>E>>s>>t;
	Graph G(V);
	G.getEdge(E);
	cout<<G.getSecondShortest(s,t);
	
	return 0;
}

