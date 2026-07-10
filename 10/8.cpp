#include<iostream>
#include<sstream>
#include<unordered_set>
#define nil nullptr
using namespace std;

struct Node{
	int data;
	Node *lft,*rht,*ftr;
	Node():lft(nil),rht(nil),ftr(nil){}
	Node(int d):data(d),lft(nil),rht(nil),ftr(nil){}
	Node(int d,Node* f):data(d),lft(nil),rht(nil),ftr(f){}
};

class Tree{
	Node* root;
	int pa;
	int qa;
	Node* pn;
	Node* qn;
	void build(istringstream &is,Node* &p,Node* f){
		int x;
		if(!(is>>x))return;
		if(x==-1)return;
		p = new Node(x,f);
		if(x==pa)pn=p;
		if(x==qa)qn=p;
		build(is,p->lft,p);
		build(is,p->rht,p);
	}
	void destroy(Node* p){
		if(p==nil)return;
		destroy(p->lft);
		destroy(p->rht);
		delete p;
	}
	public:
		Tree():root(nil){}
		Tree(string inp,int a,int b):pa(a),qa(b),pn(nil),qn(nil){
			istringstream is(inp);
			build(is,root,nil);
		}
		~Tree(){
			destroy(root);
		}
		int LCA(){
			if(pn==nil or qn==nil)return -1;
			unordered_set<Node*> us;
			Node* p=pn;
			while(p!=nil){
				us.insert(p);
				p=p->ftr;
			}
			p=qn;
			while(p!=nil){
				auto i=us.find(p);
				if(i!=us.end() and (*i)==p)return p->data;
				p=p->ftr;
			}
			return -1;
		}
};

int main(){
	string inp;
	int a,b;
	cin>>a>>b;
	getline(cin>>ws,inp);
	Tree tr(inp,a,b);
	cout<<tr.LCA();
	return 0;
}

