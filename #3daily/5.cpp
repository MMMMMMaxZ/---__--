#include<iostream>
using namespace std;

template<typename T>
class imiStack{
	public:
		imiStack(int memory_size):size(0),MaxSize(memory_size){
			lst = new T[memory_size];
		}
		~imiStack(){
			delete[] lst;
		}
		bool push(T x){
			if(size==MaxSize){
				cout<<"FULL\n";
				return false;
			}
			lst[size++]=x;
			return true;
		}
		bool top(){
			if(size==0){
				cout<<"EMPTY\n";
				return false;
			}
			cout<<lst[size-1]<<endl;
			return true;
		}
		bool pop(){
			bool NotEmpty = top();
			if(NotEmpty){
				size--;
			}
			return true;
		}
		bool getSize(){
			cout<<size<<endl;
			return true;
		}
	private:
		T* lst;
		int size;
		int MaxSize;
};

int main(){
	int n,m;
	cin>>n>>m;
	imiStack<int> s(n);
	string inp;
	int x;
	while(m--){
		cin>>ws>>inp;
		if(inp=="PUSH"){
			cin>>x;
			s.push(x);
		}else if(inp=="TOP"){
			s.top();
		}else if(inp=="POP"){
			s.pop();
		}else{
			s.getSize();
		}
	}
	
	return 0;
}

