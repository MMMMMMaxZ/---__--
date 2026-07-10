#include<iostream>
using namespace std;

struct Node{
	int v;
	Node *lft,*rht;
	Node(int v=0):v(v),lft(nullptr),rht(nullptr){}
};

class BST{
	Node* root;
	public:
		BST():root(nullptr){}
		Node* find(int x){
			//if(root==nullptr)return nullptr;
			Node* p = root,*lp=nullptr;
			while(p!=nullptr and p->v!=x){
				lp=p;
				if(x>(p->v))p=p->rht;
				else p=p->lft;
			}
			if(p==nullptr)return lp;
			return p;
		}
		void insert(int x){
			Node* p = find(x);
			if(p==nullptr){//root=nullptr
				root = new Node(x);
			}else{
				if(p->v==x)return;
				if(x<(p->v))p->lft = new Node(x);
				else p->rht = new Node(x);
			}
		}
		Node* getMax(){
			return getMax(root);
		}
		Node* getMax(Node* p){
			if(p==nullptr)return nullptr;
			while(p->rht!=nullptr)p=p->rht;
			return p;
		}
		Node* getMin(){
			return getMin(root);
		}
		Node* getMin(Node* p){
			if(p==nullptr)return nullptr;
			while(p->lft!=nullptr)p=p->lft;
			return p;
		}
		Node* getFather(Node* q){
			int x=q->v;
			Node* p = root,*lp=nullptr;
			while(p!=nullptr and p->v!=x){
				lp=p;
				if(x>(p->v))p=p->rht;
				else p=p->lft;
			}
			return lp;
		}
		bool del(int x){
			Node* p = find(x);
			if(p==nullptr or (p->v)!=x)return false;
			if(p->lft==nullptr and p->rht==nullptr){
				if(p==root){
					delete root;
					root = nullptr;
					return true;
				}
				Node* f = getFather(p);
				if(x<f->v)f->lft=nullptr;
				else f->rht=nullptr;
				delete p;
			}else if(p->lft!=nullptr and p->rht==nullptr){
				if(p==root){
					root = p->lft;
					delete p;
					return true;
				}
				Node* f = getFather(p);
				if(x<f->v){
					f->lft = p->lft;
					
				}else{
					f->rht = p->lft;
				}
				delete p;
			}else if(p->lft==nullptr and p->rht!=nullptr){
				if(p==root){
					root = p->rht;
					delete p;
					return true;
				}
				Node* f = getFather(p);
				if(x<f->v){
					f->lft = p->rht;
					
				}else{
					f->rht = p->rht;
				}
				delete p;
			}else{
				Node* m = getMax(p->lft);
				int mx = m->v;
				del(m->v);
				p->v=mx;
			}
			return true;
		}
};

int main(){
	BST bt;
	int T;
	cin>>T;
	string s;
	int x;
	while(T--){
		cin>>s;
		if(s=="INSERT"){
			cin>>x;
			bt.insert(x);
		}else if(s=="DELETE"){
			cin>>x;
			bool suc=bt.del(x);
			if(!suc){
				cout<<"NOT FOUND\n";
			}
		}else if(s=="FIND"){
			cin>>x;
			Node* f = bt.find(x);
			if(f==nullptr or f->v!=x)cout<<"NO\n";
			else cout<<"YES\n";
		}else if(s=="MIN"){
			Node* m = bt.getMin();
			if(m==nullptr)cout<<"EMPTY\n";
			else cout<<(m->v)<<endl;
		}else if(s=="MAX"){
			Node* m = bt.getMax();
			if(m==nullptr)cout<<"EMPTY\n";
			else cout<<(m->v)<<endl;
		}
	}
	return 0;
}

