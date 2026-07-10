#include<iostream>
#include<queue>
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
	Node* lft,*rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(int d):d(d),lft(nullptr),rht(nullptr){}
};

class tree{
	Node* root;
	int d;
	int depth(Node* p){
		if(p==nullptr)return 0;
		int ld = depth(p->lft),rd = depth(p->rht);
		d = max(d,ld+rd);
		return max(ld,rd)+1;
	}
	public:
		tree():root(nullptr),d(0){}
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
			}
			depth(root);
		}
		int query(){
			return d;
		}
};

int main(){
	tree tr;
	tr.build();
	cout<<tr.query();
	return 0;
}

