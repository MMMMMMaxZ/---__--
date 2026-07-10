#include<iostream>
using namespace std;

template<typename T>
struct Node{
	T data;
	Node<T>* next;
	Node(T id=0):data(id),next(NULL){}
};

template<typename T>
class List{
public:
	Node<T>* head;
	Node<T>* end;
	int len;
	List(){
		head = new Node<T>();
		end = head;
		len=0;
	}
	~List(){
		Node<T>* pre,*p;
		pre = head;
		p = pre->next;
		while(p!=NULL){
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}
	void push_back(T d){
		Node<T>* newNode = new Node<T>(d);
		end->next = newNode;
		end = newNode;
		len++;
	}
	void push_front(T d){
		Node<T>* newNode = new Node<T>(d);
		newNode->next = head->next;
		head->next = newNode;
		len++;
	}
	Node<T>* getI(int idx){
		if(idx<-1 or idx>=len)return NULL;
		Node<T>* pre=head;
		for(int i=-1;i<idx;i++){
			pre=pre->next;
		}
		return pre;
	}
	bool deleteNode(int idx){//0~n-1
		if(idx<0 or idx>=len)return false;
		Node<T>* pre=getI(idx-1);
		Node<T>* q = pre->next;
		pre->next = pre->next->next;
		delete q;
		len--;
		return true;
	}
	int insert(Node<T>* location,Node<T>* p,Node<T>* pre){
		if(location==NULL or p==NULL or pre==NULL)return -1;
		if(location==pre)return 0;
		pre->next = p->next;
		p->next = location->next;
		location->next = p;
		return 1;
	}
	void print(){
		Node<T>* p = head->next;
		while(p!=NULL){
			cout<<p->data<<' ';
			p=p->next;
		}
		cout<<endl;
	}
};

template<typename T>
void getLinkList(List<T> &lst,int k){
	T x;
	for(int i=0;i<k;i++){
		cin>>x;
		lst.push_back(x);
	}
}

template<typename T>
void solution(List<T> &lst){
	Node<T>* add = lst.head;
	Node<T>* p = lst.head->next;
	Node<T>* pre = lst.head;
	while(p!=NULL){
		if(p->data<0){
			Node<T>* q=p->next;
			int state = lst.insert(add,p,pre);
			add = p;
			p = q;
			if(state==0)pre = pre->next;
		}else{
			pre = pre->next;
			p = p->next;
		}
	}
}

int main(){
	int k;
	cin>>k;
	List<int> lst;
	getLinkList<int>(lst,k);
	solution<int>(lst);
	lst.print();
	
	
	return 0;
}
