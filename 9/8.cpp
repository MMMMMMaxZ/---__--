#include<iostream>
#include<sstream>
#include<queue>
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
			build(is);
		}
		~Tree(){
			destroy(root);
		}
		void build(istringstream &is){
			T x;
			bool rhtNode = false;
			stack<Node<T>*> stk;
			if(!(is>>x))return;
			root = new Node<T>(x);
			Node<T>* lstNode = root;
			while(is>>x){
				if(x=='('){
					rhtNode=false;
					stk.push(lstNode);
				}else if(x==','){
					rhtNode=true;
				}else if(x==')'){
					stk.pop();
				}else{
					Node<T>* tp = stk.top();
					if(!rhtNode){
						tp->lft = new Node<T>(x);
						lstNode = tp->lft;
					}else{
						tp->rht = new Node<T>(x);
						lstNode = tp->rht;
					}
				}
			}
		}
		Node<T>* getRoot(){
			return root;
		}
		void printFront(Node<T>* node){
			if(node==nullptr)return;
			cout<<node->data;
			printFront(node->lft);
			printFront(node->rht);
		}
		void printMid(Node<T>* node){
			if(node==nullptr)return;
			printMid(node->lft);
			cout<<node->data;
			printMid(node->rht);
		}
		void printRear(Node<T>* node){
			if(node==nullptr)return;
			printRear(node->lft);
			printRear(node->rht);
			cout<<node->data;
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree<char> bt1(inp);
	bt1.printFront(bt1.getRoot());cout<<endl;
	bt1.printMid(bt1.getRoot());cout<<endl;
	bt1.printRear(bt1.getRoot());
	return 0;
}
