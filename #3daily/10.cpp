#include<iostream>
#include<stack>
using namespace std;

int solution(string inp){
	int len = (int)inp.length();
	stack<int> nums;
	int x=0;
	bool getNum=false;//非负整数 
	for(int i=0;i<len;i++){
		char ch = inp[i];
		if(ch>='0' and ch<='9'){
			x = x*10+ch-'0';
			getNum=true;
		}else if(ch==' ' and getNum){
			nums.push(x);
			x=0;
			getNum=false;
		}else if(ch=='+'){
			int x = nums.top();nums.pop();
			int y = nums.top();nums.pop();
			nums.push(y+x);
		}else if(ch=='-'){
			int x = nums.top();nums.pop();
			int y = nums.top();nums.pop();
			nums.push(y-x);
		}else if(ch=='*'){
			int x = nums.top();nums.pop();
			int y = nums.top();nums.pop();
			nums.push(y*x);
		}else if(ch=='/'){
			int x = nums.top();nums.pop();
			int y = nums.top();nums.pop();
			nums.push(y/x);
		}
	}
	int ans = nums.top();nums.pop();
	return ans;
}

int main(){
	string inp;
	getline(cin,inp);
	cout<<solution(inp);
	return 0;
}

