#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* nxt;
	Node():nxt(nullptr){}
	Node(int x):data(x),nxt(nullptr){}
};

class LinkList{
	Node* front;
	public:
		LinkList():front(nullptr){
		}
		~LinkList(){
			Node* p=front;
			if(p==nullptr)return;
			Node* q=p->nxt;
			while(q!=nullptr){
				delete p;
				p = q;
				q=q->nxt;
			}
			delete p;
		}
		void get(int n){
			if(n<1)return;
			int x;
			cin>>x;
			front = new Node(x);
			Node* tail = front;
			for(int i=1;i<n;i++){
				cin>>x;
				tail->nxt = new Node(x);
				tail=tail->nxt;
			}
		}
		Node* getFront(){
			return front;
		}
		int maxNode(Node* p){//p与p后面的所有节点的最大值比较 
			if(p->nxt==nullptr)return p->data;
			return max(p->data,maxNode(p->nxt));
		}
		int minNode(Node* p){
			if(p->nxt==nullptr)return p->data;
			return min(p->data,minNode(p->nxt));
		}
};

int main(){
	int n;
	LinkList l;
	cin>>n;
	l.get(n);
	cout<<l.maxNode(l.getFront())<<endl;
	cout<<l.minNode(l.getFront())<<endl;
	return 0;
}

