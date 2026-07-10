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
			build(is);
		}
		~Tree(){
			destroy(root);
		}

		// ? 修复正确的建树函数
		void build(istringstream &is) {
			stack<Node<T>*> stk;
			Node<T>* cur = nullptr;
			bool swc=false;
			char ch;
			while (is >> ch) {
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
					cur = new Node<T>(ch);
					if (!root) root = cur;
					if (!stk.empty()) {
						if (!swc)
							stk.top()->lft = cur;
						else
							stk.top()->rht = cur;
					}
				} else if (ch == '(') {
					if (cur) stk.push(cur);
					swc = false;
					cur = nullptr;
				} else if (ch == ')') {
					if (!stk.empty()) stk.pop();
				} else if (ch == ',') {
					swc = true;
				}
			}
		}

		Node<T>* getRoot(){ return root; }
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
	bt1.printFront(bt1.getRoot()); cout<<endl;
	bt1.printMid(bt1.getRoot()); cout<<endl;
	bt1.printRear(bt1.getRoot());
	return 0;
}
