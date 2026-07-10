#include<iostream>
#include<stack>
#include<queue>
using namespace std;

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
		int find(int k){
			return find(root,k);
		}
		int find(Node* p,int &k){
			if(p==nullptr)return -1;
			int l=find(p->lft,k);
			if(l!=-1)return l;
			k--;
			if(k==0){
				return p->v;
			}
			int r=find(p->rht,k);
			if(r!=-1)return r;
			return -1;
		}
};

int main(){
	int x;cin>>x;
	Tree tr;
	tr.build();
	cout<<tr.find(x);
	return 0;
}

