#include<iostream>
#include<queue>
using namespace std;

queue<int> a,b;
int m;
string inp;int x;

void push(int x){
	a.push(x);
}

void top(bool pop){
	if(a.empty()){
		cout<<"EMPTY\n";
		return;
	}
	while(a.size()!=1){
		b.push(a.front());
		a.pop();
	}
	cout<<a.front()<<endl;
	if(not pop)b.push(a.front());
	a.pop();
	while(not b.empty()){
		a.push(b.front());
		b.pop();
	}
}

int main(){
	cin>>m;
	while(m--){
		cin>>inp;
		if(inp=="PUSH"){
			cin>>x;
			push(x);
		}else if(inp=="TOP"){
			top(0);
		}else{
			top(1);
		}
	}
	return 0;
}

