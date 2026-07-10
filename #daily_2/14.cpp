#include<iostream>
using namespace std;

struct Node{
	bool isOpt;
	int value;
	int lft,rht;
	Node(bool isOpt=0,int val=0,int lft=-1,int rht=-1)
	:isOpt(isOpt),value(val),lft(lft),rht(rht)
	{}
};

class optT{
	Node* nodeList;
	int root;
	int size;
	public:
		optT(int n):root(-1),size(n){
			nodeList = new Node[n];
		}
		void add(int id,bool isOpt=0,int val=0,int lft=-1,int rht=-1){
			nodeList[id]={isOpt,val,lft,rht};
		}
		int trs(string s){
			if((s[0]<'0' or s[0]>'9') and (int)s.length()==1)return s[0];
			bool isNeg=false;
			int st = 0,l=s.length();
			int x=0;
			if(s[0]=='-'){
				isNeg=true;
				st=1;
			}
			for(int i=st;i<l;i++)x=x*10+s[i]-'0';
			if(isNeg)x=0-x;
			return x;
		}
		void build(){
			bool hasF[size];
			for(int i=0;i<size;i++)hasF[i]=false;
			for(int i=0;i<size;i++){
				int x,y,z,w,v;
				string s;
				cin>>x>>y>>s>>z>>w;
				v=trs(s);
				add(x,y==1,v,z,w);
				if(z!=-1)hasF[z]=true;
				if(w!=-1)hasF[w]=true;
			}
			for(int i=0;i<size;i++){
				if(not hasF[i])root=i;
			}
		}
		int cal(){
			return cal(root);
		}
		int cal(int id){
			if(id==-1)return 0;
			if(nodeList[id].isOpt==false)return nodeList[id].value;
			char opt = (char)nodeList[id].value;
			int l=nodeList[id].lft , r=nodeList[id].rht;
			switch(opt){
				case '+':
					return cal(l)+cal(r);
				case '-':
					return cal(l)-cal(r);
				case '*':
					return cal(r)*cal(l);
				case '/':
					return cal(l)/cal(r);
				default:
					return 0;
			}
            return 0;
		}
};

int main(){
	int n;
	cin>>n;
	optT ot(n);
	ot.build();
	cout<<ot.cal();
	return 0;
}

