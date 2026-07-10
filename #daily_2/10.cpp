#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int v;
	Node *lft,*rht;
	Node(int v=0):v(v),lft(nullptr),rht(nullptr){}
};

struct cmpNode{
	Node *p;
	cmpNode(Node* p):p(p){}
	bool operator<(const cmpNode& x)const{
		return ((p->v) < ((x.p)->v));
	}
	bool operator>(const cmpNode& x)const{
		return ((p->v) > ((x.p)->v));
	}
};

class HFM{
	Node *root;
	public:
		HFM():root(nullptr){}
		void build(){
			int n;
			priority_queue<cmpNode,vector<cmpNode>,greater<cmpNode>> pq;
			cin>>n;
			for(int i=0;i<n;i++){
				int x;
				cin>>x;
				Node* p = new Node(x);
				pq.push(cmpNode(p));
			}
			while(pq.size()>1){
				cmpNode t1=pq.top();pq.pop();
				cmpNode t2=pq.top();pq.pop();
				Node* nn = new Node(((t1.p)->v)+((t2.p)->v));
				nn->lft = t1.p;
				nn->rht = t2.p;
				pq.push(cmpNode(nn));
			}
			cmpNode t=pq.top();pq.pop();
			root = t.p;
		}
		int WPL(){
			return WPL(root,0);
		}
		int WPL(Node *p,int depth){
			if(p==nullptr)return 0;
			if(p->lft==nullptr and p->rht==nullptr){
				//cout<<depth<<":"<<(p->v)<<"-->"<<(p->v)*depth<<endl;
				return (p->v)*depth;
			}
			return WPL(p->lft,depth+1)+WPL(p->rht,depth+1);
		}
};

int main(){
	HFM t;
	t.build();
	cout<<t.WPL();
	return 0;
}

