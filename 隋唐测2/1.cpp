#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int d,minD;
	Node *lft,*rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(int dt):d(dt),minD(dt),lft(nullptr),rht(nullptr){}
};

struct scNode{
	int d;
	Node** ptr;
	scNode *lft,*rht;
	scNode():ptr(nullptr),lft(nullptr),rht(nullptr){}
	scNode(int dt):d(dt),ptr(nullptr),lft(nullptr),rht(nullptr){}
};

class scTree{
	scNode* root;
	public:
		scTree():root(nullptr){}
		void add(int d,Node** ptr){
			if(root==nullptr){
				root = new scNode(d);
				root->ptr = ptr;
				return;
			}
			add(root,d,ptr);
		}
		void add(scNode* p,int d,Node** ptr){
			if(p==nullptr)return ;
			if(p->d == d){
				*ptr = *(p->ptr);
				return;
			}
			if(p->d > d){
				if(p->lft==nullptr){
					p->lft = new scNode(d);
					p->lft->ptr = ptr;
				}else{
					add(p->lft,d,ptr);
				}
			}
			if(p->d < d){
				if(p->rht==nullptr){
					p->rht = new scNode(d);
					p->rht->ptr = ptr;
				}else{
					add(p->rht,d,ptr);
				}
			}
		}
		Node** find(int d){
			return find(root,d);
		}
		Node** find(scNode* p,int d){
			if(p==nullptr)return nullptr;
			if(p->d==d)return p->ptr;
			if(p->d > d)return find(p->lft,d);
			if(p->d < d)return find(p->rht,d);
			return nullptr;
		}
};

class tree{
	Node* root;
	scTree bt;
	public:
		tree():root(nullptr){}
		void get(){
			int n;
			char a,b,c;
			cin>>n;
			cin>>a>>b>>c;
			root = new Node(a-'0');
			bt.add(a-'0',&root);
			if(b!='#')bt.add(b-'0',&(root->lft));
			if(c!='#')bt.add(c-'0',&(root->rht));
			for(int i=1;i<n;i++){
				cin>>a>>b>>c;
				Node** p = bt.find(a-'0');
				if(p==nullptr){
					Node *q = new Node(a-'0');
					bt.add(a-'0',&q);
					if(b!='#')bt.add(b-'0',&(q->lft));
					if(c!='#')bt.add(c-'0',&(q->rht));
					p = bt.find(a-'0');
				}else{
					(*p) = new Node(a-'0');
					if(b!='#')bt.add(b-'0',&((*p)->lft));
					if(c!='#')bt.add(c-'0',&((*p)->rht));
				}
			}
		}
		void print(){
			print(root);
		}
		void print(Node* p){
			if(p==nullptr)return;
			print(p->lft);
			print(p->rht);
			cout<<(p->d)<<' ';
		}
		int search(){
			int ans = 0;
			search(root,root->d,ans);
			return ans;
		}
		void search(Node* p,int md,int& ans){
			if(md<ans)return;
			if(p==nullptr)return;
			md = min(md,p->d);
			if(p->lft==nullptr and p->rht==nullptr){
				ans = max(md,ans);
				return;
			}
			search(p->lft,md,ans);
			search(p->rht,md,ans);
		}
};

/*
5
3 2 4
2 # #
1 # #
6 1 #
4 6 #
*/

int main(){
	tree bt;
	bt.get();
	//bt.print();cout<<endl;
	cout<<bt.search();

	return 0;
}

