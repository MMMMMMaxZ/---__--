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
	Node* head,*tail;
	public:
		Tree():root(nullptr){
			head = new Node(0);
			tail = new Node(0);
			head->rht = tail;
			tail->lft = head;
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
		void trans(){
			trans(root);
			trans(head);//ÉèÖÃÎ²½Úµã 
		}
		void trans(Node* p){
			if(p==nullptr)return;
			static Node* lstNode = head;
			if(p==head){
				lstNode->rht = tail;
				tail->lft = lstNode;
				return;
			}
			trans(p->lft);
			p->lft = lstNode;
			lstNode->rht = p;
			lstNode = p;
			trans(p->rht);
		}
		void print(){
			cout<<(head->rht->v)<<' '<<(tail->lft->v);
		}
};

int main(){
	Tree tr;
	tr.build();
	tr.trans();
	tr.print();
	return 0;
}

