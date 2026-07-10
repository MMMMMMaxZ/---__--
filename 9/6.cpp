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
		bool mirror(){
			queue<Node<T>*> ptr;
			stack<Node<T>*> stk;
			ptr.push(root);
			while(!ptr.empty()){
				if(ptr.size()==1){
					auto tp = ptr.front();
					ptr.pop();
					if(tp==nullptr)continue;
					ptr.push(tp->lft);
					ptr.push(tp->rht);
					continue;
				}else if(ptr.size()%2==1)return false;
				int sz = ptr.size();
				for(int i=0;i<sz/2;i++){
					auto tp = ptr.front();
					stk.push(tp);
					ptr.pop();
					if(tp!=nullptr){
						ptr.push(tp->lft);
						ptr.push(tp->rht);
					}
				}
				for(int i=0;i<sz/2;i++){
					auto tp = ptr.front();
					ptr.pop();
					if(tp!=nullptr){
						ptr.push(tp->lft);
						ptr.push(tp->rht);
					}
					auto sp = stk.top();
					stk.pop();
					bool t1 = (tp==nullptr),t2 = (sp==nullptr);
					if(t1^t2)return false;
					else if((tp==nullptr and sp==nullptr) or (tp->data==sp->data))continue;
					else return false;
				}
			}
			return true;
		}
};

int main(){
	string inp;
	getline(cin,inp);
	Tree<char> bt1(inp);
	if(bt1.mirror()){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}

