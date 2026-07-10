#include<iostream>
#include<stack>
using namespace std;

struct scNode{
	int d;
	pair<int,int> td;
	scNode *lft,*rht;
	scNode():td({-1,-1}),lft(nullptr),rht(nullptr){}
	scNode(int dt):d(dt),td({-1,-1}),lft(nullptr),rht(nullptr){}
};

class scTree{
	scNode* root;
	public:
		scTree():root(nullptr){}
		void add(int d,pair<int,int> td){
			if(root==nullptr){
				root = new scNode(d);
				root->td = td;
				return;
			}
			add(root,d,td);
		}
		void add(scNode* p,int d,pair<int,int> td){
			if(p==nullptr)return ;
			if(p->d == d)return;
			if(p->d > d){
				if(p->lft==nullptr){
					p->lft = new scNode(d);
					p->lft->td = td;
				}else{
					add(p->lft,d,td);
				}
			}
			if(p->d < d){
				if(p->rht==nullptr){
					p->rht = new scNode(d);
					p->rht->td = td;
				}else{
					add(p->rht,d,td);
				}
			}
		}
		pair<int,int> find(int d){
			return find(root,d);
		}
		pair<int,int> find(scNode* p,int d){
			if(p==nullptr)return {-1,-1};
			if(p->d==d)return p->td;
			if(p->d > d)return find(p->lft,d);
			if(p->d < d)return find(p->rht,d);
			return {-1,-1};
		}
		
		void print(){
			print(root);
		}
		void print(scNode* p){
			if(p==nullptr)return;
			cout<<(p->d)<<' '<<(p->td).first<<','<<(p->td).second<<endl;
			print(p->lft);
			print(p->rht);
		}
};

struct Node{
	int data;
	Node* lft,*rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(int d):data(d),lft(nullptr),rht(nullptr){}
}; 

class tree{
	scTree chd;
	int root;
	Node* rootNode;
	int ans;
	int getInput(){
		char x = ' ';
		int num = 0;
		while((x = getchar())and(x==' ' or x=='\n'));
		if(x=='#')return -1;
		num = x-'0';
		while((x=getchar())and(x>='0' and x<='9')){
			num = num*10+x-'0';
		}
		return num;
	}
	public:
		tree():root(-1),rootNode(nullptr),ans(0){}
		void get(){
			int n;
			int a,b,c;
			cin>>n;
			for(int i=0;i<n;i++){
				a=getInput();
				b=getInput();
				c=getInput();
				//cout<<"test:"<<a<<" "<<b<<" "<<c<<endl;
				if(root==-1)root = a;
				chd.add(a,{b,c});
			}
			//chd.print();
		}
		int search(){
			stack<pair<Node*,int>> stk;
			rootNode = new Node(root);
			stk.push({rootNode,root});
			while(not stk.empty()){
				auto atp = stk.top();stk.pop();
				Node* tp = atp.first;
				int md = atp.second;
				if(md<ans)continue;
				//cout<<tp->data<<endl;
				pair<int,int> ch = chd.find(tp->data);
				int l=ch.first,r=ch.second;
				if(r!=-1){
					tp->rht = new Node(r);
					if(min(r,md)>ans)stk.push({tp->rht,min(r,md)});
				}
				if(l!=-1){
					tp->lft = new Node(l);
					if(min(l,md)>ans)stk.push({tp->lft,min(l,md)});
				}
				if(l==-1 and r==-1){
					ans = max(ans,md);
				}
				
				//system("pause>nul");
			}
		    return ans;
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

