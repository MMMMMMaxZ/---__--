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
	Node<T>* getLastI(int idx){
		if(idx<1 or idx>len)return NULL;
		Node<T>*pre = head;
		Node<T>*p=head;
		for(int i=0;i<idx;i++)p=p->next;
		while(p!=NULL){
			p=p->next;
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
	void print(){
		Node<T>* p = head->next;
		while(p!=NULL){
			cout<<p->data<<' ';
			p=p->next;
		}
	}
};

template<typename T>
void getLinkList(List<T> &lst){
	T x;
	cin>>x;
	while(x!=-1){
		lst.push_back(x);
		cin>>x;
	}
}

int main(){
	int k;
	cin>>k;
	List<int> lst;
	getLinkList<int>(lst);
	Node<int>* lsNode = lst.getLastI(k);
	if(lsNode==NULL){
		cout<<-1<<endl;
		return 0;
	}
	cout<<lsNode->data<<endl;
	
	
	return 0;
}

