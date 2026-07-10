#include<iostream>
#include<stack>
using namespace std;

int main(){
	//for(int i=0;i<128;i++)cout<<i<<'-'<<(char)i<<endl;
	bool LeftType[128];
	LeftType['(']=LeftType['[']=LeftType['{']=true;
	stack<char> stk;
	string inp;
	cin>>inp;
	int len=(int)inp.length();
	for(int i=0;i<len;i++){
		char ch = inp[i];
		if(LeftType[(int)ch]){
			stk.push(ch);
		}else{
			if(stk.empty()){
				cout<<"NO";
				return 0;
			}
			char top = stk.top();stk.pop();
			if(top+1!=ch and top+2!=ch){//
				cout<<"NO";
				return 0;
			}
		}
	}
	if(not stk.empty()){
		cout<<"NO";
		return 0;
	}else{
		cout<<"YES";
	}
	return 0;
}

