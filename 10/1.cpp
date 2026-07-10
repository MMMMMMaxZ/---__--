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
		void print(vector<int> &q){//ÖÐÐò 
			print(q,root);
		}
		void print(vector<int> &q,Node* p){
			if(p==nil)return;
			print(q,p->lft);
			q.push_back(p->data);
			print(q,p->rht);
		}
		bool mirror(){
			vector<int> prt;
			print(prt);
			int l=0,r=prt.size()-1;
			while(l<=r){
				if(prt[l]!=prt[r])return false;
				l++;r--;
			}
			return true;
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree tr(inp);
	if(tr.mirror())
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}

