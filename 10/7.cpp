#include<iostream>
#include<sstream>
#include<queue>
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
		void printMid(){
			printMid(root);
			cout<<endl;
		}
		void printMid(Node* p){
			if(p==nil)return;
			printMid(p->lft);
			cout<<p->data<<' ';
			printMid(p->rht);
		}
		void printRear(){
			printRear(root);
			cout<<endl;
		}
		void printRear(Node* p){
			if(p==nil)return;
			printRear(p->lft);
			printRear(p->rht);
			cout<<p->data<<' ';
		}
		void printLevel(){
			queue<Node*> q;
			q.push(root);
			while(not q.empty()){
				auto frt = q.front();
				if(frt==nil){
					q.pop();continue;
				}
				cout<<(frt->data)<<' ';
				q.push(frt->lft);
				q.push(frt->rht);
				q.pop();
			}
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree tr(inp);
	tr.printMid();
	tr.printRear();
	tr.printLevel();
	return 0;
}

