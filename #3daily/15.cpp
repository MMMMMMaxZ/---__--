#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* nxt;
	Node(){}
	Node(int d):data(d){}
};

class Link{
	Node* head;
	public:
		Link(){
			head = new Node();
		}
		void ini(){
			int x;
			Node* p =head;
			cin>>x;
			while(x!=-1){
				p->nxt = new Node(x);
				p=p->nxt;
				cin>>x;
			}
		}
		void combine(Link &a,Link &b){
			Node* p = a.head->nxt,*q = b.head->nxt;
			Node* s = head;
			while(p!=nullptr and q!=nullptr){
				if(p->data>q->data){
					s->nxt
				}
			}
		}
};

int main(){
	return 0;
}

