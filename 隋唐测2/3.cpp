#include<iostream>
#include<stack>
using namespace std;

struct Node{
	char d;
	Node *lft,*rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(char dt):d(dt),lft(nullptr),rht(nullptr){}
};

class tree{
	Node* root;
	public:
		tree():root(nullptr){}
		tree(string s){
			build(s);
		}
		void build(string s){
			int n = s.length();
			stack<Node*> stk;
			root = new Node(s[0]);
			Node* lstNode = root;
			bool isRht = false;
			for(int i=1;i<n;i++){
				char ch = s[i];
				if(ch == '('){
					stk.push(lstNode);
					isRht = false;
				}else if(ch == ')'){
					stk.pop();
				}else if(ch == ','){
					isRht = true;
				}else{
					Node* tp = stk.top();
					if(isRht){
						tp->rht = new Node(ch);
						lstNode = tp->rht;
					}else{
						tp->lft = new Node(ch);
						lstNode = tp->lft;
					}
				}
			}
		}
		void print(){
			print(root);
		}
		void print(Node* p){
			if(p==nullptr)return;
			if(p->lft!=nullptr or p->rht!=nullptr)cout<<(p->d);
			print(p->lft);
			print(p->rht);
		}
};

int main(){
	string inp;
	tree bt;
	getline(cin,inp);
	bt.build(inp);
	bt.print();
	
	return 0;
}

