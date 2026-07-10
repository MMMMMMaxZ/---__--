#include<iostream>
using namespace std;

class stack{
	public:
		int* data;
		int top;
		int maxSize;
		stack(int memorySize):top(-1),maxSize(memorySize){
			data = new int[memorySize];
		}
		~stack(){
			delete[]data;
		}
		
		int size(){
			return top+1;
		}
		void query(){
			if(size()==0)cout<<"Anguei!"<<endl;
			else cout<<data[top]<<endl;
		}
		void pop(){
			if(size()==0)cout<<"Empty"<<endl;
			else top--;
		}
		void push(int x){
			if(top==maxSize-1)return ;
			data[++top]=x;
		}
};

int n;
int p;
string inp;

int main(){
	cin>>n;
	while(n--){
		cin>>p;
		auto *pStack = new stack(p);
		while(p--){
			cin>>inp;
			if(inp=="size")cout<<pStack->size()<<endl;
			else if(inp=="query")pStack->query();
			else if(inp=="pop")pStack->pop();
			else{
				int x;cin>>x;
				pStack->push(x);
			}
		}
		delete pStack;
	}
	return 0;
}

