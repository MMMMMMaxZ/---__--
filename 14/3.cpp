#include<iostream>
#include<queue>
using namespace std;

const int INF = 1e5+2;

struct Node{
	int d;
	Node *lft,*rht;
	Node(int d=0):d(d),lft(nullptr),rht(nullptr){}
};

class BST{
	Node* root;
	public:
		BST():root(nullptr){}
		Node* search(int x){
			if(root==nullptr)return nullptr;
			Node *p=root,*lstP = nullptr;
			while(p!=nullptr){
				lstP=p;
				if(p->d == x)return p;
				else if(x<(p->d)){
					p=p->lft;
				}else{
					p=p->rht;
				}
			}
			return lstP;
		}
		bool add(int x){
			if(root==nullptr){
				root = new Node(x);
				return true;
			}
			Node* p = search(x);
			if(p->d == x)return false;
			if(x < (p->d)){
				p->lft = new Node(x);
			}else{
				p->rht = new Node(x);
			}
			return true;
		}
		void get(int n){
			queue<Node**> q;
			q.push(&root);
			int cnt=0;
			while(!q.empty()){
				int a;
				cin>>a;
				Node** tp = q.front();q.pop();
				if(a!=-1){
					*tp = new Node(a);
					cnt++;
					if(cnt==n)break;
					q.push(&((*tp)->lft));
					q.push(&((*tp)->rht));
				}
			}
		}
		int AdSearch(int x){
			x++;//ÕÒx+1 
			int MinBig = INF;
			if(root==nullptr)return -1;
			Node* p = root;
			while(p!=nullptr){
				if(p->d == x)return x;
				else if(x<(p->d)){
					MinBig = min(MinBig,(p->d));
					p=p->lft;
				}else{
					p=p->rht;
				}
			}
			if(MinBig==INF)return -1;
			return MinBig;
		}
};

int main(){
	int n;
	BST bst;
	cin>>n;
	bst.get(n);
	int x;
	cin>>x;
	cout<<bst.AdSearch(x);
	return 0;
}

