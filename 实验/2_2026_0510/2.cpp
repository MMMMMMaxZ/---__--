#include<iostream>
#include<queue>
using namespace std;

struct Node{
	char letter;
	double data;
	Node *lft,*rht;
	Node(char l,double d):letter(l),data(d),lft(nullptr),rht(nullptr){}
	Node():lft(nullptr),rht(nullptr){}
};

struct cmpNode{
	Node* nodePTR;
	cmpNode():nodePTR(nullptr){}
	cmpNode(Node* ptr):nodePTR(ptr){}
	bool operator<(const cmpNode &p)const{
		if(nodePTR->data==p.nodePTR->data){
			if(nodePTR->letter==' ')return true;
			else if(p.nodePTR->letter==' ')return false;
			else return nodePTR->letter >= p.nodePTR->letter;
			
		}
		return nodePTR->data < p.nodePTR->data;
	}
	bool operator>(const cmpNode &p)const{
		if(nodePTR->data==p.nodePTR->data){
			if(nodePTR->letter!=' ')return true;
			else if(p.nodePTR->letter!=' ')return false;
			else return nodePTR->letter <= p.nodePTR->letter;
		}
		return nodePTR->data > p.nodePTR->data;
	}
};

class HuffmanTree{
	Node* root;
	int n;
	char letter[26];
	double posibility[26];
	void destroy(Node* p){
		if(p==nullptr)return;
		destroy(p->lft);
		destroy(p->rht);
		delete p;
	}
	public:
		HuffmanTree():root(nullptr){}
		~HuffmanTree(){
			destroy(root);
		}
		void ini();
		string read(string info);
		void test(){
			print(root);
			cout<<endl;
		}
		void print(Node* p){
			if(p==nullptr)return;
			print(p->lft);
			cout<<'['<<p->data<<','<<p->letter<<']';
			print(p->rht);
		}
};

void HuffmanTree::ini(){
	priority_queue<cmpNode> que;
	int n;
	cin>>n;
	this->n = n;
	for(int i=0;i<n;i++){
		char c,f;
		double x;
		cin>>c>>f>>x;
		Node* p = new Node(c,x*(-1.0));
		que.push(cmpNode(p));
	}
	while(que.size()>1){
		Node* p1 = (que.top()).nodePTR; que.pop();
		Node* p2 = (que.top()).nodePTR; que.pop();
		Node* newNode = new Node(' ',p1->data+p2->data);
		newNode->lft = p1;
		newNode->rht = p2;
		que.push(newNode);
	}
	root = (que.top()).nodePTR;
	que.pop();
}

string HuffmanTree::read(string info){
	Node* p = root;
	string out="";
	int len=(int)info.length();
	for(int i=0;i<len;i++){
		bool dt = info[i]-'0';
		if(dt)p=p->rht;
		else p=p->lft;
		if(p->letter!=' '){
			out+=p->letter;
			p=root;
		}
	}
	return out;
}

int main(){
	HuffmanTree HMT;
	HMT.ini();
	//HMT.test();
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	string inp;
	while(cin>>inp){
		cout<<HMT.read(inp)<<endl;
	}
	
	return 0;
}

