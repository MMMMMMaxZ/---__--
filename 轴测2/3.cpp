#include<iostream>
using namespace std;

template<typename T>
struct Node{
	T data;
	Node* nxt;
	Node(T data,Node* nxt=NULL):data(data),nxt(nxt){}
};

template<typename T>
class LinkStack{
	Node<T>* head;
	public:
		LinkStack(){
			head = new Node<T>(0);
		}
		~LinkStack(){
			Node<T>* p = head,*q=p->nxt;
			while(q!=NULL){
				delete p;
				p = q;
				q = p->nxt;
			}
			delete p;
		}
		bool empty(){
			return head->nxt==NULL;
		}
		bool push(T x){
			Node<T> *newNode = new Node<T>(x);
			newNode->nxt = head->nxt;
			head->nxt = newNode;
			return true;
		}
		bool getTop(T &x){
			Node<T> *top = head->nxt;
			if(top==NULL)return false;
			x = top->data;
			return true;
		}
		bool pop(T &x){
			Node<T> *top = head->nxt;
			if(top==NULL)return false;
			x = top->data;
			head->nxt = top->nxt;
			delete top;
			return true;
		}
		bool popK(int k,T &x){
			if(k<=0)return false;
			Node<T> *top = head->nxt,*pre=head;
			if(top==NULL)return false;
			int i=1;
			while(top!=NULL and i<k){
				pre = pre->nxt;
				top = top->nxt;
				i++;
			}
			if(top==NULL)return false;
			x = top->data;
			pre->nxt = top->nxt;
			delete top;
			return true;
		}
		void print(){
			Node<T>* p = head->nxt;
			while(p!=NULL){
				cout<<p->data<<' ';
				p = p->nxt;
			}
		}
};

int n;
LinkStack<int> a,ans;
int k;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push(x);
	}
	while(not a.empty()){
		int x=0;
		a.pop(x);
		ans.push(x);
	}
	cin>>k;
	int kElement=0;
	bool success = ans.popK(k,kElement);
	if(success){
		cout<<kElement<<endl;
	}else{
		cout<<"error\n";
	}
	ans.print();
	
	return 0;
}

