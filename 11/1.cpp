#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int val;
	Node* lft,*rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(int v):val(v),lft(nullptr),rht(nullptr){}
};

struct cmpNode{
	Node* nd;
	cmpNode(Node* ptr):nd(ptr){}
	bool operator<(const cmpNode &b)const{
		return nd->val > b.nd->val;
	}
};

class HuffTree{
	Node* root;
	void destroy(Node* p){
		if(p==nullptr)return;
		destroy(p->lft);
		destroy(p->rht);
		delete p;
	}
	public:
		HuffTree():root(nullptr){}
		~HuffTree(){
			destroy(root);
		}
		void build(){
			int n;
			priority_queue<cmpNode> pq;
			cin>>n;
			for(int i=0;i<n;i++){
				int x;
				cin>>x;
				Node *newNode = new Node(x);
				cmpNode *cnN = new cmpNode(newNode);
				pq.push(*cnN);
			}
			while(pq.size()!=1){
				auto p1 = pq.top();pq.pop();
				auto p2 = pq.top();pq.pop();
				Node *newNode = new Node(p1.nd->val + p2.nd->val);
				newNode->lft = p1.nd;
				newNode->rht = p2.nd;
				cmpNode *cnN = new cmpNode(newNode);
				pq.push(*cnN);
			}
			auto tp = pq.top();
			root = tp.nd;
			pq.pop();
		}
		int getWPL(){
			return getWPL(root,0);
		}
		int getWPL(Node* p,int depth){
			if(p==nullptr)return 0;
			//cout<<p->val<<','<<depth<<endl;
			//system("pause");
			if(p->lft==nullptr and p->rht==nullptr)
				return depth*p->val;
			else
				return getWPL(p->lft,depth+1)+getWPL(p->rht,depth+1);
		}
};

int main(){
	HuffTree bt1;
	bt1.build();
	cout<<bt1.getWPL();
	return 0;
}

