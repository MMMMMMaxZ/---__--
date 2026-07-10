#include<iostream>
using namespace std;

class stack{
	public:
		int* data;
		int top;
		int maxSize;
		int maxData;
		stack(int memorySize):top(-1),maxSize(memorySize),maxData(0){
			data = new int[memorySize];
		}
		~stack(){
			delete[]data;
		}
		
		int size(){
			return top+1;
		}
		int query(){
			return maxData;
		}
		bool pop(){
			if(size()==0)return false;
			else top--;
			if(top==-1)maxData=0;
			else if(data[top+1]==maxData){
				maxData=0;
				for(int i=0;i<=top;i++)maxData=max(maxData,data[i]);
			}
			return true;
		}
		bool push(int x){
			if(top==maxSize-1)return false;
			data[++top]=x;
			maxData = max(maxData,x);
			return true;
		}
};

int n;
int x;
int operateType;

int main(){
	cin>>n;
	stack* st = new stack(n);
	while(n--){
		cin>>operateType;
		switch(operateType){
			case 0:
				cin>>x;
				st->push(x);
				break;
			case 1:
				st->pop();
				break;
			case 2:
				cout<<st->query()<<endl;
				break;
		}
	}
	return 0;
}

