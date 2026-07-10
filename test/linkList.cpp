#include<iostream>
using namespace std;

template<typename T>
struct Node{
	int data;
	Node<T>* nxt;
	Node():nxt(nullptr){}
	Node(T d):data(d),nxt(nullptr){}
};

template<typename T>
class LinkList{
	Node<T>* head;
	public:
		LinkList(){
			head = new Node<T>();
		}
		~LinkList(){
			Node<T>* pre=head,p=pre->nxt;
			while(p!=nullptr){
				delete pre;
				pre = p;
				p = p->nxt;
			}
			delete pre;
		}
		void addHead(T d){
			Node<T>* newNode = new Node<T>(d);
			newNode->nxt = head->nxt;
			head->nxt = newNode;
		}
		void addTail(T d){
			Node<T>* newNode = new Node<T>(d);
			Node<T>* p = head;
			while(p->nxt!=nullptr)p = p->nxt;
			p->nxt = newNode;
		}
		Node<T>* getI(int i){
			if(i<-1)return nullptr;
			int j=-1;
			Node<T>* p = head;
			while(j<i and p!=nullptr){
				p=p->nxt;
				++j;
			}
			return p;
		}
		bool deleteI(int i){
			if(i<=-1)return;
			Node<T>* p = getI(i-1);
			if(p==nullptr)return false;
			if(p->nxt==nullptr)return false;
			Node<T>* q=p->nxt;
			p->nxt = q->nxt;
			delete q;
			return true;
		}
};

template<typename T>
class loopLink{
	Node<T>* head;
	public:
		loopLink(){
			head = new Node<T>();
			head->nxt = head;
		}
		~loopLink(){
			auto pre = head,p=pre->nxt;
			while(p!=head){
				delete pre;
				pre = p;
				p=p->nxt;
			}
			delete pre;
		}
};

int main(){
	return 0;
}

