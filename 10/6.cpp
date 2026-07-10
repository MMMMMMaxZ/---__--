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
		int cnt(){
			return cnt(root);
		}
		int cnt(Node* p){
			if(p==nil)return 0;
			int l = cnt(p->lft),r = cnt(p->rht);
			return l+r+1;
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree tr(inp);
	cout<<tr.cnt();
	return 0;
}

