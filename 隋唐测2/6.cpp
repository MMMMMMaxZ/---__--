#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

int get(){
	static char c(' ');
	int x=0;
	while(c==' ' or c=='\n')c=getchar();
	if(c<'0' or c>'9'){ // #
		c = ' '; // 相当于填充了下一位 
		return -1;
	}
	while(c>='0' and c<='9'){
		x = x*10 + c - '0';
		c = getchar();
	}
	return x;
}

struct Node{
	int d;
	bool ext;
	Node* lft,*rht;
	Node():ext(false),lft(nullptr),rht(nullptr){}
	Node(int d):d(d),ext(false),lft(nullptr),rht(nullptr){}
};

class tree{
	Node* root;
	int leaves;
	vector<int> vc;
	public:
		tree():root(nullptr),leaves(0){}
		void build(){
			int n;
			queue<Node**> q;
			q.push(&root);
			cin>>n;
			for(int i=0;i<n;i++){
				int a,b,c;
				a=get();b=get();c=get();
				Node** ptr = q.front();q.pop();
				(*ptr) = new Node(a);
				if(b!=-1)q.push(&((*ptr)->lft));
				if(c!=-1)q.push(&((*ptr)->rht));
				if(b==-1 and c==-1)leaves++;
			}
		}
		void solution(){
			if(root==nullptr)return;
			int mode=0,lvC=0;
			dfs(root,mode,lvC);
		}
		void dfs(Node* p,int& mode,int &lvC){//mode:0,1,2
			if(mode==0){
				if(p->lft==nullptr and p->rht==nullptr)mode=1;
				else {
					vc.push_back(p->d);
					p->ext = true;
				}
			}
			if(mode==1){
				if(p->lft==nullptr and p->rht==nullptr){
					vc.push_back(p->d);
					p->ext = true;
					lvC++;
					if(lvC==leaves)mode=2;
				}
			}
			if(p->lft != nullptr)dfs(p->lft,mode,lvC);
			if(p->rht != nullptr)dfs(p->rht,mode,lvC);
			if(mode==2){
				if(not (p->ext)){
					vc.push_back(p->d);
					p->ext = true;
				} 
			} 
		}
		void print(){
			for(auto i:vc){
				cout<<i<<' ';
			}
		}
};

int main(){
	tree tr;
	tr.build();
	tr.solution();
	tr.print();
	return 0;
}

