#include<iostream>
#include<sstream>
#include<vector>
#define nil nullptr
using namespace std;

struct Node{
	int data;
	Node *lft,*rht;
	Node():lft(nil),rht(nil){}
	Node(int d):data(d),lft(nil),rht(nil){}
};

class Tree{
	Node* root;
	void build(istringstream &is,Node* &p){
		int x;
		if(!(is>>x))return;
		if(x==-1)return;
		p = new Node(x);
		build(is,p->lft);
		build(is,p->rht);
	}
	void destroy(Node* p){
		if(p==nil)return;
		destroy(p->lft);
		destroy(p->rht);
		delete p;
	}
	public:
		Tree():root(nil){}
		Tree(string inp){
			istringstream is(inp);
			build(is,root);
		}
		~Tree(){
			destroy(root);
		}
		bool equal(Tree &tr){
			return equal(root,tr.root);
		}
		bool equal(Node* a,Node* b){
			if(a==nil and b==nil)return true;
			if(a==nil and b!=nil)return false;
			if(a!=nil and b==nil)return false;
			if(a->data!=b->data)return false;
			bool k1 = equal(a->lft,b->lft);if(not k1)return false;
			bool k2 = equal(a->rht,b->rht);if(not k2)return false;
			return true;
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree tr1(inp);
	getline(cin>>ws,inp);
	Tree tr2(inp);
	if(tr1.equal(tr2))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}

