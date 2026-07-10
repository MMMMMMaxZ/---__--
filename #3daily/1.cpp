#include<iostream>
#include<stack>
using namespace std;

stack<char> opt;
int x=0;
bool flag = 0;
int lv[200];

inline void ini(){
	for(int i='0';i<='9';i++)
		lv[i]=1;
	lv['+']=lv['-']=2;
	lv['*']=lv['/']=3;
	lv['(']=lv[')']=4;
}

int main(){
	ini();
	char inp;
	while((inp = getchar()) != EOF){
		if(inp=='\n')break;
		if(lv[(int)inp]==1){
			flag=1;
			x=x*10+(inp-'0');
		}else{
			if(flag){
				cout<<x<<' ';
				x=0;
				flag=0;
			}
			if(opt.size()==0){
				opt.push(inp);
				continue;
			}else{
				char tp = opt.top();
				if(tp=='('){
					opt.push(inp);
					continue;
				}else if(inp==')'){
					while(!opt.empty() and tp!='('){
						cout<<tp<<' ';
						if(!opt.empty())opt.pop();
						if(!opt.empty())tp=opt.top();
					}
					if(!opt.empty())opt.pop();
				}else if(lv[(int)inp]<=lv[(int)tp]){
					while(tp!='(' and lv[(int)inp]<=lv[(int)tp]){
						cout<<tp<<' ';
						opt.pop();
						if(opt.size()==0)break;
						tp=opt.top();
					}
					opt.push(inp);
				}else{
					opt.push(inp);
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

