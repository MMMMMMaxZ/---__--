#include<iostream>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;

class NP{
	vector<int> vc;
	public:
		bool validStr(string s){
			int l=s.length();
			stack<bool> stk;
			for(int i=0;i<l;i++){
				char c = s[i];
				if(c=='(')stk.push(1);
				else if(c=='-'){
					if(i!=0 and s[i-1]!='(' and (s[i-1]<'0' or s[i-1]>'9'))return false;
				}else if(c==')'){
					if(stk.empty())return false;
					stk.pop();
				}else if(c<'0' or c>'9'){
					if(i!=0 and (s[i-1]<'0' or s[i-1]>'9') and s[i-1]!='(' and s[i-1]!=')')return false;
				}
			}
			if(!stk.empty())return false;
			return true;
		}
		int level(int x){
			if(x<0 or x>=128)return 0;
			if(x=='(' or x==')')return 1;
			if(x=='+' or x=='-')return 2;
			if(x=='*' or x=='/')return 3;
		}
		int getX(int& p,string s){
			//0-127:char(0->error),<0 & >=128:int
			int l = s.length();
			if(p<0 or p>=l)return 0;
			char c = s[p];
			bool getNum=false,isNeg=false;
			int x=0;
			if(c=='-'){
				if(p==0 or s[p-1]=='('){
					isNeg=true;
					getNum=true;
				}
			}else if(c>='0' and c<='9'){
				getNum=true;
				x = c-'0';
			}
			p++;
			if(getNum){
				while(s[p]>='0' and s[p]<='9'){
					x=x*10+s[p]-'0';
					p++;
				}
			}else{//opt
				x=c;
			}
			if(getNum and isNeg)x=-1*x;
			else if(getNum) x+=128;
			return x;
		}
		string trans(int x){
			ostringstream os;
			if(x<0)os<<x;
			else if(x>=128)os<<x-128;
			else os<<char(x);
			return os.str();
		}
		void build(string s){
			if(!validStr(s)){
				cout<<"Invalid!\n";
				return;
			}
			int x,p=0;
			stack<int> opt;
			while(x=getX(p,s)){
				cout<<trans(x)<<' ';
				int lv = level(x);
				if(lv==0)vc.push_back(x);
				else{
					if(opt.empty())opt.push(x);
					else{
						int tp=opt.top();
						int tlv = level(tp);
						if(x=='(')opt.push(x);
						else if(tlv<lv)opt.push(x);
						else{
							while(!opt.empty() and tlv>=lv){
								if(x==')' and tp=='('){
									opt.pop();
									break;
								}
								vc.push_back(tp);
								opt.pop();
								if(opt.empty())break;
								tp=opt.top();
								tlv=level(tp);
							}
							if(x!=')')opt.push(x);
						}
					}
				}
			}
			while(!opt.empty()){
				vc.push_back(opt.top());
				opt.pop();
			}
			cout<<endl;
		}
		void print(){
			for(auto x:vc){
				cout<<trans(x)<<' ';
			}
			cout<<endl;
		}
};

int main(){
	string s;
	cin>>s;
	NP np;
	np.build(s);
	np.print();
	return 0;
}

