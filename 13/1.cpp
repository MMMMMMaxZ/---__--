#include<iostream>
#include<stack>
using namespace std;

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
	public:
		Graph(int n):size(n){
			edges = new headNode[n];
		}
		void getEdge(int e){
			int u,v;
			for(int i=0;i<e;i++){
				cin>>u>>v;
				Node* newV = new Node(v);
				newV->nxt = edges[u].e;
				edges[u].e = newV;
				Node* newU = new Node(u);
				newU->nxt = edges[v].e;
				edges[v].e = newU;
			}
		}
		int getConnected(){
			int cnt=0;
			bool visited[size]={0};
			for(int i=0;i<size;i++){
				if(visited[i]==0){
					cnt++;
					search(i,visited);
				}
			}
			return cnt;
		}
		void search(int i,bool visited[]){
			stack<int> stk;
			stk.push(i);
			while(!stk.empty()){
				int tp = stk.top();stk.pop();
				visited[tp]=1;
				Node* p = edges[tp].e;
				while(p!=nullptr){
					if(!visited[p->v])stk.push(p->v);
					p=p->nxt;
				}
			}
		}
};

int main(){
	int V,E;
	cin>>V>>E;
	Graph G(V);
	G.getEdge(E);
	cout<<G.getConnected();
	
	return 0;
}

