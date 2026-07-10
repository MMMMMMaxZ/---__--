#include<iostream>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;

struct Node{
	int v;
	Node *lft,*rht;
	Node(int v=0):v(v),lft(nullptr),rht(nullptr){}
};

class Tree{
	Node* root;
	int get(int& p,string &s){
		int l=s.length();
		if(p<0 or p>=l)return 0;
		int x=0;
		bool getNum=false,isNeg=false;
		int c=s[p];
		if(c==','){
			p++;
			return get(p,s);
		}
		else if(c=='#'){
			p++;
			return -1;
		}else if(c=='-'){
			getNum=true;
			isNeg = true;
			p++;
		}else{
			getNum=true;
			x = c-'0';
			p++;
		}
		if(getNum){
			while(s[p]>='0' and s[p]<='9'){
				x=x*10+s[p]-'0';
				p++;
			}
		}
		if(isNeg)x=0-x;
		return x;
	}
	public:
		Tree():root(nullptr){
		}
		void build(){
			int x;
			stack<Node**> stk;
			stk.push(&root);
			while(!stk.empty() and (cin>>x)){
				Node** tp = stk.top();stk.pop();
				if(x==-1)continue;
				(*tp) = new Node(x);
				stk.push(&((*tp)->rht));
				stk.push(&((*tp)->lft));
			}
		}
		void find(int x,int y){
			bool found = false;
			find(x,y,root,found);
			if(!found){
				cout<<"-1";
			}
		}
		int find(int x,int y,Node* p,bool &found){
			if(found)return 0;
			if(p==nullptr)return 0;
			int s=0;
			int l=find(x,y,p->lft,found);
			int r=find(x,y,p->rht,found);
			s = l+r;
			if(p->v==x)s+=x;
			if(p->v==y)s+=y;
			//cout<<(p->v)<<" -> "<<s<<endl;
			if(s==x+y){
				cout<<p->v<<endl;
				found = true;
				return 0;
			}else{
				return s;
			}
		}
};

int main(){
	int x,y;
	cin>>x>>y;
	if(x==y){
		cout<<x;
		return 0;
	}
	Tree tr1;
	tr1.build();
	tr1.find(x,y);
	return 0;
}

