#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

struct Node{
	int data;//1-127：char，128-INF || <0：int 
	Node *lft,*rht;
	Node(int d):data(d),lft(nullptr),rht(nullptr){};
	Node():lft(nullptr),rht(nullptr){}
};

class CalClass{
	public:
		bool isLetter(char inp){
			return (inp>='A' and inp<='Z')or(inp>='a' and inp<='z');
		}
};

class CalTree:public CalClass{
	Node* root;
	public:
		CalTree():root(nullptr){}
		CalTree(string inp){
			root = build_tree(inp);
		}
		bool isNum(char inp){
			return inp>='0' and inp<='9';
		}
		int OPTlevel(char inp){
			if(inp=='*' or inp=='/')return 2;
			if(inp=='+' or inp=='-')return 1;
			if(inp=='(' or inp==')')return 0;
			return -1; 
		}
		int read(string inp,int &p){
		//读取，1-127：char，128-INF || <0：int 
		//0 : End Of Reading
			if(p>=(int)inp.length())return 0;
			int x=0;
			bool getNum=false,isNeg=false;
			char tp = inp[p];
			if(tp == '-'){
				if(p==0 or inp[p-1]=='('){//负号
					getNum = true;
					isNeg = true;
					p++;
				}
			}else if(isNum(tp)){
				getNum = true;
				x = tp-'0';
				p++;
			}
			if(getNum){//数字
				while(isNum(inp[p])){
					x = x*10 + (int)inp[p] - '0';
					p++;
				}
				if(isNeg)return -1*x;
				else return 128+x;
			}else{//运算符 
				p++;
				return tp;
			}
		}
		Node* build_tree(string inp){
			int p=0,x;
			stack<Node*> num;
			stack<char> opt;
			while((x = read(inp,p))!=0){
				if(x>=128 or x<0){//数字
					Node* newNode = new Node(x);
					num.push(newNode);
				}else if(isLetter((char)x)){//字母 
					Node* newNode = new Node(x);
					num.push(newNode);
				}else{//符号
					int lvl = OPTlevel((char)x);
					if(opt.empty() or x=='('){
						opt.push(x);
					}else if(x==')'){
						if(opt.empty())return nullptr;
						while((not opt.empty()) and opt.top()!='('){
							char tp = opt.top();
							if(num.size()<2)return nullptr;
							Node* p1 = num.top();num.pop();
							Node* p2 = num.top();num.pop();
							Node* newNode = new Node(tp);
							newNode->rht = p1;
							newNode->lft = p2;
							num.push(newNode);
							opt.pop();
						}
						if(opt.empty())return nullptr;
						opt.pop();//'('弹出 
					}else{
						char tp = opt.top();
						if(OPTlevel(tp)<lvl){
							opt.push(x);
						}else{
							while((not opt.empty()) and OPTlevel(opt.top())>=lvl){
								tp = opt.top();
								if(num.size()<2)return nullptr;
								Node* p1 = num.top();num.pop();
								Node* p2 = num.top();num.pop();
								Node* newNode = new Node(tp);
								newNode->rht = p1;
								newNode->lft = p2;
								num.push(newNode);
								opt.pop();
							}
							opt.push(x);
						}
					}
				}
			}
			while(not opt.empty()){
				char tp = opt.top();
				if(num.size()<2)return nullptr;
				Node* p1 = num.top();num.pop();
				Node* p2 = num.top();num.pop();
				Node* newNode = new Node(tp);
				newNode->rht = p1;
				newNode->lft = p2;
				num.push(newNode);
				opt.pop();
			}
			if(num.size()!=1)return nullptr;
			return num.top();
		}
		void build(string inp){
			root = build_tree(inp);
		}
		Node* getRoot(){
			return root;
		}
		void print(){
			print(root);
		}
		void print(Node* p){
			if(p==nullptr)return;
			cout<<'(';
			print(p->lft);
			if(p->data>=0 and p->data<128)cout<<'['<<(char)p->data<<']';
			else if(p->data>=128)cout<<'['<<p->data-128<<']';
			else if(p->data<0)cout<<'['<<p->data<<']';
			print(p->rht);
			cout<<')';
		}
		int calculate(){
			return calculate(root);
		}
		int calculate(Node* p){
			if(p->data<0)return p->data;
			else if(p->data>=128)return p->data-128;
			else if(isLetter((char)p->data))return p->data;
			else{
				switch((char)p->data){
					case '+':
						return calculate(p->lft)+calculate(p->rht);
					case '-':
						return calculate(p->lft)-calculate(p->rht);
					case '*':
						return calculate(p->lft)*calculate(p->rht);
					case '/':
						return calculate(p->lft)/calculate(p->rht);
					default:
						return 0;
				}
			}
		}
};

class rvQue:public CalClass{
	vector<Node*> data;
	int size;
	public:
		rvQue():size(0){}
		rvQue(CalTree ctr){
			build(ctr);
		}
		void build(CalTree ctr){
			size = 0;
			data.push_back(ctr.getRoot());
			while(size!=(int)data.size()){
				Node* frt = data[size];
				if(frt->lft!=nullptr)data.push_back(frt->lft);
				if(frt->rht!=nullptr)data.push_back(frt->rht);
				size++;
			}
		}
		void print(){
			for(auto i = data.rbegin();i!=data.rend();i++){
				int dt = (*i)->data;
				if(dt>=0 and dt<128)cout<<(char)dt;
				else if(dt>=128)cout<<dt-128;
				else if(dt<0)cout<<dt;
			}
			cout<<endl;
		}
		int calculate(){
			queue<int> nums;
			for(auto i = data.rbegin();i!=data.rend();i++){
				int dt = (*i)->data;
				if(isLetter((char)dt))nums.push(dt);//字母 
				else if(dt>=128)nums.push(dt-128);//正数 
				else if(dt<0)nums.push(dt);//负数 
				else{//运算符 
					int a,b;
					switch((char)dt){
						case '+':
							if(nums.size()<2)return -1;
							b = nums.front();nums.pop();
							a = nums.front();nums.pop();
							nums.push(a+b);
							break;
						case '-':
							if(nums.size()<2)return -1;
							b = nums.front();nums.pop();
							a = nums.front();nums.pop();
							nums.push(a-b);
							break;
						case '*':
							if(nums.size()<2)return -1;
							b = nums.front();nums.pop();
							a = nums.front();nums.pop();
							nums.push(a*b);
							break;
						case '/':
							if(nums.size()<2)return -1;
							b = nums.front();nums.pop();
							a = nums.front();nums.pop();
							nums.push(a/b);
							break;
					}
				}
			}
			if(nums.size()!=1)return -1;
			return nums.front();
		}
};

int main(){
	CalTree t;
	rvQue r;
	string s;
	getline(cin,s);
	t.build(s);
	r.build(t);
	//t.print();
	cout<<t.calculate()<<endl;
	r.print();
	cout<<r.calculate()<<endl;
	
	return 0;
}

