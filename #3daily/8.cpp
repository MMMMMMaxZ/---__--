#include<iostream>
using namespace std;

template<typename T>
struct Node{
	T data;
	Node<T>* nxt;
	Node():nxt(nullptr){}
	Node(T d):data(d),nxt(nullptr){}
};

template<typename T>
class LinkStack{
	Node<T>* head;
	public:
		LinkStack(){
			head = new Node<T>();
		}
		~LinkStack(){
			Node<T>* p=head,*q=p->nxt;
			while(q!=nullptr){
				delete p;
				p=q;
				q=q->nxt;
			}
			delete p;
		}
		bool is_empty(bool show){
			bool rtn = head->nxt == nullptr;
			if(show){
				if(rtn)cout<<"YES\n";
				else cout<<"NO\n";
			}
			return rtn;
		}
		void push(T x){
			Node<T> *newNode = new Node<T>(x);
			newNode->nxt = head->nxt;
			head->nxt = newNode;
		}
		Node<T>* top(){
			if(is_empty(false)){
				cout<<"EMPTY\n";return nullptr;
			}
			Node<T>* top = head->nxt;
			cout<<top->data<<endl;
			return top;
		}
		void pop(){
			auto tp = top();
			if(tp==nullptr)return;
			head->nxt = tp->nxt;
			delete tp;
		}
		
};

int main(){
	int T;
	LinkStack<int> stk;
	cin>>T;
	while(T--){
		string inp;
		cin>>inp;
		if(inp=="PUSH"){
			int x;
			cin>>x;
			stk.push(x);
		}else if(inp=="POP"){
			stk.pop();
		}else if(inp=="TOP"){
			stk.top();
		}else{
			stk.is_empty(true);
		}
	}
	return 0;
}

