#include<iostream>
#include<stack>
#include<queue>
using namespace std;

const int INF = 1e4+2;

struct Node{
	int v;
	Node *lft,*rht;
	Node(int v=0):v(v),lft(nullptr),rht(nullptr){}
};

class Tree{
	Node* root;
	public:
		Tree():root(nullptr){
		}
		void build(){
			int x;
			stack<Node**> stk;
			stk.push(&root);
			while(!stk.empty() and (cin>>x)){
				Node** tp = stk.top();stk.pop();
				if(x==-1)continue;
				(*tp) = new Node(x);
				stk.push(&((*tp)->rht));
				stk.push(&((*tp)->lft));
			}
		}
		bool isBST(){
			return isBST(root,-INF,INF);
		}
		bool isBST(Node* p,int lb,int rb){
			if(p==nullptr)return true;
			if(p->v<=lb or p->v>=rb)return false;
			//if(p->lft!=nullptr and (p->v)<=(p->lft->v))return false;
			//if(p->rht!=nullptr and (p->v)>=(p->rht->v))return false;
			bool l=isBST(p->lft,lb,p->v);
			if(!l)return false;
			bool r=isBST(p->rht,p->v,rb);
			return r;
		}
};

int main(){
	Tree tr;
	tr.build();
	bool is = tr.isBST();
	if(is)cout<<"YES";
	else cout<<"NO";
	return 0;
}

