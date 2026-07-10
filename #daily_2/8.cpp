#include<iostream>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;

struct Node{
	int v;
	Node *lft,*rht;
	Node(int v=0):v(v),lft(nullptr),rht(nullptr){}
};

class Tree{
	Node* root;
	int get(int& p,string &s){
		int l=s.length();
		if(p<0 or p>=l)return 0;
		int x=0;
		bool getNum=false,isNeg=false;
		int c=s[p];
		if(c==','){
			p++;
			return get(p,s);
		}
		else if(c=='#'){
			p++;
			return -1;
		}else if(c=='-'){
			getNum=true;
			isNeg = true;
			p++;
		}else{
			getNum=true;
			x = c-'0';
			p++;
		}
		if(getNum){
			while(s[p]>='0' and s[p]<='9'){
				x=x*10+s[p]-'0';
				p++;
			}
		}
		if(isNeg)x=0-x;
		return x;
	}
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
		void printM(){
			printM(root);
			cout<<endl;
		}
		void printM(Node* p){
			if(p==nullptr)return;
			printM(p->lft);
			cout<<(p->v)<<' ';
			printM(p->rht);
		}
		void printT(){
			printT(root);
			cout<<endl;
		}
		void printT(Node* p){
			if(p==nullptr)return;
			printT(p->lft);
			printT(p->rht);
			cout<<(p->v)<<' ';
		}
		void printL(){
			if(root==nullptr)return;
			queue<Node*> q;
			q.push(root);
			while(!q.empty()){
				int sz = q.size();
				for(int i=0;i<sz;i++){
					Node* tp = q.front();q.pop();
					if(tp==nullptr)continue;
					cout<<(tp->v)<<' ';
					q.push(tp->lft);
					q.push(tp->rht);
				}
			}
			cout<<endl;
		}
};

int main(){
	Tree tr1;
	tr1.build();
	tr1.printM();
	tr1.printT();
	tr1.printL();
	return 0;
}

