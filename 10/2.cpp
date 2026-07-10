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
		void mirror(){
			mirror(root);
		}
		void mirror(Node* p){
			if(p==nil)return;
			mirror(p->lft);
			mirror(p->rht);
			swap(p->lft,p->rht);
		}
		void print(){
			print(root);
		}
		void print(Node* p){
			if(p==nil)return;
			cout<<p->data<<' ';
			print(p->lft);
			print(p->rht);
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree tr(inp);
	tr.mirror();
	tr.print();
	return 0;
}

