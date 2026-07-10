#include<iostream>
#include<stack>
using namespace std;

stack<int> a,b;
int m;
string input;
int inpX;

void ENQUEUE(int x){
	while(not b.empty()){
		a.push(b.top());
		b.pop();
	}
	a.push(x);
}

void PEEK(){
	while(not a.empty()){
		b.push(a.top());
		a.pop();
	}
	if(b.empty()){
		cout<<"EMPTY\n";
		return ;
	}
	cout<<b.top()<<endl;
}

void DEQUEUE(){
	PEEK();
	b.pop();
}

int main(){
	cin>>m;
	while(m--){
		cin>>ws>>input;
		if(input=="ENQUEUE"){
			cin>>inpX;
			ENQUEUE(inpX);
		}else if(input=="DEQUEUE"){
			DEQUEUE();
		}else{
			PEEK();
		}
	}
	
	
	return 0;
}

