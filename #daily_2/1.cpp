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
		bool isMir(){
			if(root==nullptr)return true;
			queue<Node*> q;
			stack<int> stk;
			q.push(root->lft);
			q.push(root->rht);
			while(!q.empty()){
				int sz = q.size();
				if(sz%2!=0)return false;
				for(int i=0;i<sz/2;i++){
					Node* tp = q.front();q.pop();
					if(tp==nullptr)stk.push(-1);
					else stk.push(tp->v);
					if(tp!=nullptr){
						q.push(tp->lft);
						q.push(tp->rht);
					}
				}
				for(int i=sz/2;i<sz;i++){
					Node* tp = q.front();q.pop();
					if(stk.empty())return false;
					int stp = stk.top();
					int v = (tp==nullptr)?-1:(tp->v);
					if(stp==v)stk.pop();
					else return false;
					if(tp!=nullptr){
						q.push(tp->lft);
						q.push(tp->rht);
					}
				}
				if(!stk.empty())return false;
			}
			return true;
		}
};

int main(){
	Tree tr;
	tr.build();
	bool isM = tr.isMir();
	if(isM)cout<<"YES";
	else cout<<"NO";
	return 0;
}

