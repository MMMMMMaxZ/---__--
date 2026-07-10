#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* nxt;
	Node():nxt(nullptr){}
	Node(int d):data(d),nxt(nullptr){}
};

const int N=1e5+2;

class link{
	Node* head;
	public:
		link(){
			head = new Node();
		}
		void ini(int n){
			int nxt[N];
			Node* nodes[N];
			int p=1;nodes[0]=nullptr;
			while(n--){
				int d,nx;
				cin>>d>>nx;
				if(nx==-1)nx=0;
				nodes[p] = new Node(d);
				nxt[p++] = nx;
			}
			for(int i=1;i<p;i++){
				nodes[i]->nxt = nodes[nxt[i]];
			}
			head->nxt = nodes[1];
		}
		bool circle(){
			if(head->nxt==nullptr)return false;
			Node* p=head,*q=head;
			while(q!=nullptr){
				q = q->nxt;
				p=p->nxt;
				if(q!=nullptr)q=q->nxt;
				if(p==q)break;
			}
			if(p==q and q!=nullptr)return true;
			else return false;
		}
};

int main(){
	int n;
	cin>>n;
	link k;
	k.ini(n);
	if(k.circle()){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	return 0;
}

