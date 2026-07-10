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
		}
		void getEdge(){
			bool w;
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					cin>>w;
					if(w){
						Node* newV = new Node(j,1);
						newV->nxt = edges[i].e;
						edges[i].e = newV;
					}
				}
			}
		}
		void solution(int v){
			vector<vector<int>> A(size,vector<int>(size));
			for(int i=0;i<size;i++)
				for(int j=0;j<size;j++)
					A[i][j]=(i==j)?0:INF;
			for(int i=0;i<size;i++){
				Node* p = edges[i].e;
				while(p!=nullptr){
					A[i][p->v]=1;
					p=p->nxt;
				}
			}
			for(int k=0;k<size;k++){
				for(int i=0;i<size;i++){
					for(int j=0;j<size;j++){
						A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
					}
				}
			}
			/*for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					cout<<A[i][j]<<' ';
				}
				cout<<endl;
			}*/
			int maxLength = -INF;
			vector<int> maxI;
			for(int i=0;i<size;i++){
				if(i==v)continue;
				if(A[i][v]>INF-100)continue;
				if(A[i][v]>maxLength){
					maxLength = A[i][v];
					maxI.clear();
					maxI.push_back(i);
				}else if(A[i][v]==maxLength){
					maxI.push_back(i);
				}
			}
			if(maxI.empty()){
				cout<<-1;
				return;
			}
			for(auto i:maxI){
				cout<<i<<' ';
			}
		}
};

int main(){
	int V,v;
	cin>>V;
	Graph G(V);
	G.getEdge();
	cin>>v;
	G.solution(v);
	return 0;
}

