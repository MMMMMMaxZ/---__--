#include<iostream>
#include<stack>
using namespace std;

stack<char> opt;
string inp;
int x=0;
bool flag = 0;
int lv [200];

inline void ini(){
	for(int i='0';i<='9';i++)
		lv[i]=1;
	lv['+']=lv['-']=2;
	lv['*']=lv['/']=3;
	lv['(']=lv[')']=4;
}

int main(){
	ini();
	getline(cin,inp);
	int len = (int)inp.length();
	for(int i=0;i<len;i++){
		if(lv[(int)inp[i]]==1){
			flag=1;
			x=x*10+(inp[i]-'0');
		}else{
			if(flag){
				cout<<x<<' ';
				x=0;
				flag=0;
			}
			if(opt.size()==0){
				opt.push(inp[i]);
				continue;
			}else{
				char tp = opt.top();
				if(tp=='('){
					opt.push(inp[i]);
					continue;
				}else if(inp[i]==')'){
					while(tp!='('){
						cout<<tp<<' ';
						opt.pop();
						tp=opt.top();
					}
					opt.pop();
				}else if(lv[(int)inp[i]]<=lv[(int)tp]){
					while(lv[(int)inp[i]]<=lv[(int)tp]){
						cout<<tp<<' ';
						opt.pop();
						if(opt.size()==0)break;
						tp=opt.top();
					}
					opt.push(inp[i]);
				}else{
					opt.push(inp[i]);
				}
			}
		}
	}
	if(flag){cout<<x<<' ';}
	while(opt.size()!=0){
		char tp=opt.top();
		cout<<tp<<' ';
		opt.pop();
	}
	
	return 0;
}

