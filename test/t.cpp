#include<iostream>
#include<stack>
using namespace std;

stack<int> left;
string input;

int main(){
	for(int i=0;i<128;i++)cout<<(char)i<<endl;
	getline(cin,input);
	for(int i=0;i<input.length();i++){
		if(input[i]=='(' or input[i]=='[' or input[i]=='{')
			left.push(input[i]);
		if(input[i]==')'or input[i]==']' or input[i]=='}'){
			char tp = left.top();
			
		}
	}
	return 0;
}

