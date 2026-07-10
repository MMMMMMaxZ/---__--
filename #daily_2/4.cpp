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
		void build(string s){
			int p=0,x;
			stack<Node**> stk;
			stk.push(&root);
			while(!stk.empty() and (x=get(p,s))){
				Node** tp = stk.top();stk.pop();
				if(x==-1)continue;
				(*tp) = new Node(x);
				stk.push(&((*tp)->rht));
				stk.push(&((*tp)->lft));
			}
		}
		string str(){
			ostringstream os;
			if(root==nullptr)return "#";
			os<<(root->v);
			str(os,root->lft);
			str(os,root->rht);
			return os.str();
		}
		void str(ostringstream &os,Node* p){
			if(p==nullptr){
				os<<",#";
				return ;
			}
			os<<','<<(p->v);
			str(os,p->lft);
			str(os,p->rht);
		}
		void print(){
			print(root);
		}
		void print(Node* p){
			if(p==nullptr)return;
			print(p->lft);
			cout<<(p->v)<<' ';
			print(p->rht);
		}
};

int main(){
	Tree tr1,tr2;
	tr1.build();
	string s1 = tr1.str();
	cout<<s1<<endl;
	tr2.build(s1);
	tr2.print();
	return 0;
}

