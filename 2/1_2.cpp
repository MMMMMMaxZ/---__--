#include<iostream>
#include<map>
#include<queue>
#include<stack>
using namespace std;

struct Node;

const int N=110;
map<int,Node*> AdToNode;
int n,HAD;
int tAD,tX,tNX;

struct Node{
	int cur;
	int data;
	int nxt;
	Node(int d=0,int icur=0,int inxt=0):cur(icur),data(d),nxt(inxt){
		AdToNode[icur]=this;
	}
};

class List{
	public:
	Node* head;
	List(int add){
		head = new Node(0,-2,add);
	}
	~List(){
		Node *pre,*p;
		pre = head;
		p = AdToNode[pre->nxt];
		while(p!=NULL){
			delete pre;
			pre = p;
			p = AdToNode[p->nxt];
		}
		delete pre;
	}
	void push(int d,int cur,int nxt){
		new Node(d,cur,nxt);
	}
	bool insert(Node* pos,Node* pre,Node* p){
		if(pos==NULL or pre==NULL or p==NULL)return false;
		if(pos==pre)return true;
		pre->nxt = p->nxt;
		p->nxt = pos->nxt;
		pos->nxt=p->cur;
		return true;
	}
	void print(){
		Node* p=head;
		p = AdToNode[p->nxt];
		while(p->nxt!=-1){
			printf("%05d %d %05d\n",p->cur,p->data,p->nxt);
			p = AdToNode[p->nxt];
		}
		printf("%05d %d -1\n",p->cur,p->data);
	}
};

void solution(List &lst){
	//654 123 (将后半段倒叙)
	Node* p=lst.head,*pre,*q;
	for(int i=0;i<n/2;i++){
		pre=p;
		p=AdToNode[p->nxt];
	}
	pre=p;
	p=AdToNode[p->nxt];
	q=p;
	for(int i=n/2;i<n;i++){
		lst.insert(lst.head,pre,p);
		p=AdToNode[pre->nxt];
	}
	//615243 (将前半段插入后半段) 
	pre=lst.head;
	p=AdToNode[lst.head->nxt];
	for(int i=n/2;i<n;i++){
		lst.insert(q,pre,p);
		p=AdToNode[pre->nxt];
		q=AdToNode[q->nxt];
		q=AdToNode[q->nxt];
	}
	
}

int main(){
	AdToNode[-1]=NULL;
	cin>>HAD>>n;
	List lst(HAD);
	for(int i=0;i<n;i++){
		cin>>tAD>>tX>>tNX;
		lst.push(tX,tAD,tNX);
	}
	solution(lst);
	lst.print();
	
	return 0;
}

