#include<iostream>
using namespace std;

template<typename T>
class LinkList;

template<typename T>
struct ListNode{
	T* data;
	int size;
	int p;//point
	ListNode* nxt;
	LinkList<T>* list;//没用了哈哈哈忘记删了 
	ListNode(int size, LinkList<T>* list, ListNode* nxt=NULL)
	:size(size),p(0),nxt(nxt),list(list){
		data = new T[size];
	}
	ListNode(const ListNode& copy){
		size = copy.size;
		p = copy.p;
		nxt = NULL;
		list = NULL;
		data = new T[size];
		for(int i=0;i<p;i++){
			data[i]=copy.data[i];
		}
	}
	~ListNode(){
		delete[] data;
	}
	bool addData(T x){
		if(p==size)return false;
		data[p++]=x;
		return true;
	}
	T getK(int k){
		return data[k];
	}
	void print(){
		for(int i=0;i<p-1;i++){
			cout<<data[i]<<' ';
		}
		cout<<data[p-1];
	}
};

template<typename T>
class LinkList{
	ListNode<T>* head;
	ListNode<T>* tail;
	int nodeSize;
	public:
		LinkList(int nodeSize=0):nodeSize(nodeSize){
			head = new ListNode<T>(1,this);
			tail = head;
		}
		~LinkList(){
			ListNode<T>* pre=head,*p=head->nxt;
			while(p!=NULL){
				delete pre;
				pre = p;
				p = p->nxt;
			}
			delete pre;
		}
		void resetNodeSize(int size){
			nodeSize = size;
		}
		bool empty(){
			return tail==head;
		}
		void addNode(){
			ListNode<T>* newNode = new ListNode<T>(nodeSize,this);
			tail->nxt = newNode;
			tail = newNode;
		}
		void push(T x){
			if(empty())addNode();
			bool success = tail->addData(x);
			if(success)return;
			addNode();
			tail->addData(x);
		}
		void push(ListNode<T>* p){
			tail->nxt = p;
			tail = p;
			p->nxt = NULL;
			p->list = this;
		}
		template<typename J>
		friend void solution(LinkList<J> &R,LinkList<J> &S, LinkList<J> &C,int i,int j);
};

template<typename T>
void solution(LinkList<T> &R,LinkList<T> &S, LinkList<T> &C,int i,int j){
	auto p = R.head->nxt,q=S.head->nxt;
	while(p!=NULL){
		q=S.head->nxt;
		while(q!=NULL){
			auto a=new ListNode<T>(*p),b=new ListNode<T>(*q);
			auto a_i = a->getK(i-1),b_j = b->getK(j-1);
			if(a_i>b_j){
				C.push(a);
				C.push(b);
			}
			q=q->nxt;
		}
		p=p->nxt;
	}
	auto c = C.head->nxt;
	while(c!=NULL){
		c->print();
		c=c->nxt;
		cout<<' ';
		c->print();
		if(c->nxt!=NULL)cout<<endl;
		c=c->nxt;
	}
}

int main(){
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		if(i>1)cout<<"\n\n";
		string inp;
		cin>>inp;
		cout<<"第"<<i<<"个"<<inp<<"样例:\n";
		if(inp=="char"){
			int m1,n1,m2,n2,i,j;
			LinkList<char> R,S,C;
			cin>>m1>>n1;
			R.resetNodeSize(n1);
			for(int i=0;i<m1*n1;i++){
				char x;
				cin>>x;
				R.push(x);
			}
			cin>>m2>>n2;
			S.resetNodeSize(n2);
			for(int i=0;i<m2*n2;i++){
				char x;
				cin>>x;
				S.push(x);
			}
			cin>>i>>j;
			if(i>n1 or j>n2){
				cout<<"列号超出范围!";
				continue;
			}
			solution<char>(R,S,C,i,j);
		}else if(inp=="int"){
			int m1,n1,m2,n2,i,j;
			LinkList<int> R,S,C;
			cin>>m1>>n1;
			R.resetNodeSize(n1);
			for(int i=0;i<m1*n1;i++){
				int x;
				cin>>x;
				R.push(x);
			}
			cin>>m2>>n2;
			S.resetNodeSize(n2);
			for(int i=0;i<m2*n2;i++){
				int x;
				cin>>x;
				S.push(x);
			}
			cin>>i>>j;
			if(i>n1 or j>n2){
				cout<<"列号超出范围!";
				continue;
			}
			solution<int>(R,S,C,i,j);
		}else{
			int n,m;
			cin>>m>>n;
			cout<<"未知的数据类型: "<<inp;
			continue;
		}
	}
	return 0;
}

