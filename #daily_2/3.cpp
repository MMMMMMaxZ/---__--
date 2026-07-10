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
		int depth(){
			return depth(root);
		}
		int depth(Node* p){
			if(p==nullptr)return 0;
			return 1+max(depth(p->lft),depth(p->rht));
		}
		void print(){
			print(root);
		}
		void print(Node* p){
			if(p==nullptr){
				return;
			}
			cout<<(p->v)<<' ';
			print(p->lft);
			print(p->rht);
		}
};

int main(){
	Tree tr;
	tr.build();
	cout<<tr.depth();
	return 0;
}

