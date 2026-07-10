#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int v;
	Node *lft,*rht;
	Node(int v=0):v(v),lft(nullptr),rht(nullptr){}
};

class tr{
	Node* root;
	public:
		tr():root(nullptr){}
		void build(vector<int> &a,vector<int> &b){
			int n=a.size();
			put(&root,a,b,{0,n-1},{0,n-1});
		}
		void put(Node** pp,vector<int> &a,vector<int> &b,pair<int,int> q1,pair<int,int> q2){
			int l1 = q1.first,r1 = q1.second;
			int l2 = q2.first,r2 = q2.second;
			if(l1>r1 or l2>r2)return;
			Node* p = new Node(a[l1]);
			(*pp) = p;
			int x = l2;
			while(b[x]!=a[l1])x++;
			put(&(p->lft),a,b,{l1+1,l1+(x-l2)},{l2,x-1});
			put(&(p->rht),a,b,{l1+(x-l2)+1,r1},{x+1,r2});
		}
		void printT(){
			printT(root);
			cout<<endl;
		}
		void printT(Node* p){
			if(p==nullptr)return;
			printT(p->lft);
			printT(p->rht);
			cout<<(p->v)<<' ';
		}
		
};

int main(){
	tr t;
	vector<int> a,b;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<n;i++){
		cin>>x;
		b.push_back(x);
	}
	t.build(a,b);
	t.printT();
	return 0;
}

