#include<iostream>
#include<sstream>
#include<queue>
using namespace std;

template<typename T>
struct Node{
	T data;
	Node* lft,*rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(T d):data(d),lft(nullptr),rht(nullptr){}
};

template<typename T>
class Tree{
	Node<T>* root;
	void destroy(Node<T>* p){
		if(p==nullptr)return;
		destroy(p->lft);
		destroy(p->rht);
		delete p;
	}
	void copy(Node<T>* &p,Node<T>* &q){
		if(q==nullptr)return;
		p = new Node<T>(q->data);
		copy(p->lft,q->lft);
		copy(p->rht,q->rht);
	}
	public:
		Tree():root(nullptr){}
		Tree(string inp){
			root=nullptr;
			istringstream is(inp);
			build(is,root);
		}
		Tree(Tree &cpy){
			copy(root,cpy.root);
		}
		~Tree(){
			destroy(root);
		}
		void build(istringstream &is,Node<T>* &node){
			T x;
			if(!(is>>x))return;
			if(x=='#')return;
			node = new Node<T>(x);
			build(is,node->lft);
			build(is,node->rht);
		}
		Node<T>* getRoot(){
			return root;
		}
		void printFront(Node<T>* node){
			if(node==nullptr)return;
			cout<<node->data<<' ';
			printFront(node->lft);
			printFront(node->rht);
		}
		void printMid(Node<T>* node){
			if(node==nullptr)return;
			printMid(node->lft);
			cout<<node->data<<' ';
			printMid(node->rht);
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree<char> bt1(inp);
	Tree<char> bt2(bt1);
	bt2.printMid(bt2.getRoot());
	return 0;
}

