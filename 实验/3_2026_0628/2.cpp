#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

struct Node{
	int data;
	int cnt;
	Node *lft,*rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(int d):data(d),cnt(1),lft(nullptr),rht(nullptr){}
};

class BT{
	Node* root;
	void destroy(Node* p){
		if(p==nullptr)return;
		destroy(p->lft);
		destroy(p->rht);
		delete p;
	}
	public:
		BT(){
			root=nullptr;
		}
		~BT(){
			destroy(root);
		}
		void add(int x){
			if(root==nullptr){
				root = new Node(x);
				return ;
			}
			auto tp = search(x);
			Node* p = tp.first;
			if(p->data==x) p->cnt++;
			else if(x<p->data){
				p->lft = new Node(x);
			}else{
				p->rht = new Node(x);
			}
		}
		pair<Node*,int> search(int x){
			if(root==nullptr)return {nullptr,0};
			int cnt=1;
			Node* p = root;
			while(p->data!=x){
				if(x<p->data){
					if(p->lft==nullptr)break;
					p=p->lft;
				}else{
					if(p->rht==nullptr)break;
					p=p->rht;
				}
				cnt++;
			}
			return {p,cnt};
		}
		pair<Node*,Node*> betterSearch(int x){
			Node* p = root;
			Node* lstP = nullptr;
			while(p->data!=x){
				lstP = p;
				if(x<p->data){
					if(p->lft==nullptr)break;
					p=p->lft;
				}else{
					if(p->rht==nullptr)break;
					p=p->rht;
				}
			}
			return {p,lstP};
		}
		void deleteNode(int x){
			auto tp = betterSearch(x);
			Node* p = tp.first;
			Node* fp = tp.second;
			if(x!=p->data)return;
			if(p==root and p->lft==nullptr and p->rht==nullptr and p->cnt==1){
				delete p;
				root = nullptr;
				return;
			}
			if(p->cnt>1){
				p->cnt--;
				return;
			}
			if(p->lft==nullptr and p->rht==nullptr){
				if((p->data) < (fp->data)){
					fp->lft = nullptr;
					delete p;
				}else{
					fp->rht = nullptr;
					delete p;
				}
			}
			else if(p->lft!=nullptr and p->rht==nullptr){
				if((p->data) < (fp->data)){
					fp->lft = p->lft;
					delete p;
				}else{
					fp->rht = p->lft;
					delete p;
				}
			}
			else if(p->rht!=nullptr and p->lft==nullptr){
				if((p->data) < (fp->data)){
					fp->lft = p->rht;
					delete p;
				}else{
					fp->rht = p->rht;
					delete p;
				}
			}
			else{//both
				Node* ld = p->lft;
				Node* lld = p;
				while(ld->rht!=nullptr){
					lld = ld;
					ld=ld->rht;
				}
				p->data = ld->data;
				p->cnt = ld->cnt;
				if(ld->lft==nullptr){
					if(lld==p){
						lld->lft=nullptr;
					}else{
						lld->rht=ld->lft;
					}
				}else{
					if(lld==p){
						lld->lft = ld->lft;
					}else{
						lld->rht = ld->lft;
					}
				}
				delete ld;
			}
		}
		void printQ(){
			printQ(root);
		}
		void printQ(Node* p){
			if(p==nullptr)return;
			cout<<p->data<<'|'<<p->cnt;
			if(p->lft!=nullptr or p->rht!=nullptr){
				cout<<'(';
				printQ(p->lft);
				cout<<',';
				printQ(p->rht);
				cout<<')';
			}
		}
		void print(){
			print(root);
		}
		void print(Node* p){
			if(p==nullptr)return;
			print(p->lft);
			cout<<p->data<<' ';
			print(p->rht);
		}
		void getQue(vector<int> &v){
			push(v,root);
		}
		void push(vector<int> &v,Node*p){
			if(p==nullptr)return;
			push(v,p->lft);
			v.push_back(p->data);
			push(v,p->rht);
		}
};

int search(int x,vector<int> &v){
	/*int l=0 , r = v.size();
	int mid = (l+r)>>1;
	int cnt=1;
	while(l<r and v[mid]!=x){
		if(x<v[mid]){
			r=mid;
		}else{
			l=mid+1;
		}
		mid = (l+r)>>1;
		cnt++;
	}
	if(l>=r)cnt--;
	return cnt;*/
	
	int cnt=0;
	int mid,l=0,r=v.size()-1;
	while(l<=r){
		cnt++;
		mid = l + ((r-l)>>1);
		if(v[mid]<x){
			l = mid + 1;
		}else if(v[mid]>x){
			r = mid - 1;
		}else{
			return cnt;
		}
	}
	return cnt;
}

int main(){
	string s;
	getline(cin,s);
	istringstream is(s);
	int x;
	BT bt;
	while(is>>x){
		bt.add(x);
	}
	bt.printQ();cout<<endl;
	cin>>x;
	bt.deleteNode(x);
	bt.print();cout<<endl;
	vector<int> vq;
	bt.getQue(vq);
	cin>>x;
	cout<<search(x,vq);
	return 0;
}

