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
	public:
		Tree():root(nullptr){}
		Tree(string inp){
			root=nullptr;
			istringstream is(inp);
			build(is,root);
		}
		~Tree(){
			destroy(root);
		}
		void build(istringstream &is,Node<T>* &node){
			T x;
			if(!(is>>x))return;
			if(x==-1)return;
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
		void printRear(Node<T>* node){
			if(node==nullptr)return;
			printRear(node->lft);
			printRear(node->rht);
			cout<<node->data<<' ';
		}
		void printLevel(){
			queue<Node<T>*> ptr;
			ptr.push(root);
			while(!ptr.empty()){
				auto tp = ptr.front();
				ptr.pop();
				if(tp==nullptr)continue;
				cout<<tp->data<<' ';
				ptr.push(tp->lft);
				ptr.push(tp->rht);
			}
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree<int> tr(inp);
	tr.printMid(tr.getRoot());cout<<endl;
	tr.printRear(tr.getRoot());cout<<endl;
	tr.printLevel();cout<<endl;
	return 0;
}

