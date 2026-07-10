#include<iostream>
using namespace std;

struct Node{
	char data;
	Node* nxt;
	Node* nxtVal;
	Node():nxt(nullptr),nxtVal(nullptr){}
	Node(char x):data(x),nxt(nullptr),nxtVal(nullptr){}
};

class linkStr{
	Node* head;
	Node* tailNxtVal;
	public:
		linkStr(){
			head = new Node();
			tailNxtVal = nullptr;
		}
		linkStr(string str){
			head = new Node();
			Node* p=head;
			int len=str.length();
			for(int i=0;i<len;i++){
				Node* q = new Node(str[i]);
				p->nxt=q;
				p=q;
			}
			tailNxtVal = nullptr;
		}
		~linkStr(){
			Node* pre=head,*p=head->nxt;
			while(p!=nullptr){
				delete pre;
				pre = p;
				p=p->nxt;
			}
			delete pre;
		}
		void get(){
			char x;
			Node* p=head;
			x=getchar();
			while(x!='\n'){
				Node* q = new Node(x);
				p->nxt=q;
				p=q;
				x=getchar();
			}
		}
		void getNxtVal(){//¶Ôt 
			Node* k = head,*i = head->nxt;
			if(i==nullptr)return;
			i->nxtVal=head;
			while(i!=nullptr){
				if(k==head or k->data==i->data){
					k=k->nxt;
					i=i->nxt;
					if(i==nullptr){
						tailNxtVal = k;
					}else if(k->data!=i->data){
						i->nxtVal=k;
					}else{
						i->nxtVal=k->nxtVal;
					}
				}else{
					k=k->nxtVal;
				}
			}
		}
		int countSubStr(linkStr &t){//¶Ôs 
			int cnt=0;
			t.getNxtVal();
			Node *i=head->nxt,*j=t.head->nxt;
			while(i!=nullptr and j!=nullptr){
				if(j==t.head or i->data==j->data){
					i=i->nxt;
					j=j->nxt;
					if(j==nullptr){
						cnt++;
						j=t.tailNxtVal;
					}
				}else{
					j=j->nxtVal;
				}
			}
			return cnt;
		}
};

int main(){
	linkStr a,b;
	a.get();
	b.get();
	cout<<a.countSubStr(b);
	
	return 0;
}

