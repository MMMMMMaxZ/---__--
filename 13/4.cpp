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
		Graph(int n):size(n){
			edges = new headNode[n+2];
			for(int i=0;i<n;i++){
				Node* newN = new Node(i,0);
				newN->nxt = edges[i].e;
				edges[i].e = newN;
			}
		}
		void getEdge(int m){
			int u,v,w;
			for(int i=0;i<m;i++){
				cin>>u>>v>>w;
				u--;v--;
				Node* newN = new Node(v,w);
				newN->nxt = edges[u].e;
				edges[u].e = newN;
			}
		}
		void solution(){
			vector<vector<int>> A(size,vector<int>(size,INF));
			for(int i=0;i<size;i++)
					A[i][i]=0;
			for(int i=0;i<size;i++){
				Node* p = edges[i].e;
				while(p!=nullptr){
					A[i][p->v]=p->w;
					p=p->nxt;
				}
			}
			for(int k=0;k<size;k++){
				for(int i=0;i<size;i++){
					for(int j=0;j<size;j++){
						if(A[i][j]==INF and (A[i][k]==INF or A[k][j]==INF))continue;
						A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
					}
				}
			}
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					if(A[i][j]>=INF-24)
						cout<<"INF ";
					else
						cout<<A[i][j]<<' ';
				}
				cout<<endl;
			}
			
		}
};

int main(){
	int V,M;
	cin>>V>>M;
	Graph G(V);
	G.getEdge(M);
	G.solution();
	return 0;
}

