#include<iostream>
using namespace std;

struct Node{
	bool isEnd;
	Node* lft,*rht;//0,1
	Node(bool e=false):isEnd(e),lft(nullptr),rht(nullptr){}
};

class codeTree{
	Node* root;
	public:
		codeTree(){
			root = new Node;
		}
		bool addNewCode(string s){
			int l = s.length();
			Node *p=root;
			for(int i=0;i<l;i++){
				bool ch = (s[i]=='1');
				if(ch){//1->lft
					if(p->lft==nullptr){
						p->lft = new Node;
						p = p->lft;
					}else{
						if(p->lft->isEnd)return false;
						else if(i==l-1)return false;
						p = p->lft;
					}
				}else{//0->rht
					if(p->rht==nullptr){
						p->rht = new Node;
						p = p->rht;
					}else{
						if(p->rht->isEnd)return false;
						else if(i==l-1)return false;
						p = p->rht;
					}
				}
			}
			return true;
		}
};

int main(){
	freopen("in.txt","r+",stdin);
	string s;
	codeTree ct1;
	bool flg = true;
	while(getline(cin>>ws,s)){
		if(s=="9")break;
		flg = flg and ct1.addNewCode(s);
	}
	if(flg)cout<<"Y";
	else cout<<"N";
	return 0;
}

