#include<iostream>
#include<sstream>
#include<stack>
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
			if(x=='#')return;
			node = new Node<T>(x);
			build(is,node->lft);
			build(is,node->rht);
		}
		Node<T>* getRoot(){
			return root;
		}
		void printLevel(){
			stack<Node<T>*> ptr;
			ptr.push(root);
			while(!ptr.empty()){
				auto tp = ptr.top();
				ptr.pop();
				if(tp==nullptr)continue;
				if(tp->lft==nullptr and tp->rht==nullptr)cout<<tp->data<<' ';
				ptr.push(tp->lft);
				ptr.push(tp->rht);
			}
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree<char> bt1(inp);
	bt1.printLevel();
	return 0;
}

