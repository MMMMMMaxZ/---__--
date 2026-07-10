#include<iostream>
#include<sstream>
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
		int depth(Node<T>* node){
			if(node==nullptr)return 0;
			return max(depth(node->lft),depth(node->rht))+1;
		}
		void print(Node<T>* node){
			if(node==nullptr)return;
			cout<<node->data<<' ';
			print(node->lft);
			print(node->rht);
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree<int> tr(inp);
	cout<<tr.depth(tr.getRoot())<<endl;
	return 0;
}

