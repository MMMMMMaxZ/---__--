#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* nxt;
	Node():nxt(nullptr){}
	Node(int d):data(d),nxt(nullptr){}
};

class link{
	Node* front; // 其实front指向第一个人的前一个，即最后一个 
	public:
		link():front(nullptr){}
		void ini(int n){
			Node* p=new Node(1);
			front = p;
			for(int i=2;i<=n;i++){
				p->nxt=new Node(i);
				p=p->nxt;
			}
			p->nxt=front;
			front = p;
		}
		bool empty(){
			return front==nullptr;
		}
		bool erase(Node* p){//删除的是下一个
			if(empty())return false;
			if(p->nxt == p){
				delete p;
				front = nullptr;
				return true;
			}
			front = p;
			Node* dq = p->nxt;
			p->nxt = (p->nxt)->nxt;
			delete dq;
			return true;
		}
		void solution(int m){
			Node *p = front;
			while(not empty()){
				for(int i=0;i<m-1;i++)p=p->nxt;
				cout<<p->nxt->data<<' ';
				erase(p);
			}
		}
};

int main(){
	link lk;
	int n,m;
	cin>>n>>m;
	lk.ini(n);
	lk.solution(m);
	return 0;
}

