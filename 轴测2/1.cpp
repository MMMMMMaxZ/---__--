#include<iostream>
using namespace std;

template<typename T>
class stack{
	T* data;
	int top;
	int maxSize;
	public:
		stack(int size):maxSize(size){
			data = new T[size];
			top = -1;
		}
		~stack(){
			delete[] data;
		}
		bool empty(){
			return top==-1;
		}
		bool push(T x){
			if(top==maxSize-1)return false;
			data[++top]=x;
			return true;
		}
		bool pop(T &x){
			if(empty())return false;
			x = data[top--];
			return true;
		}
		bool getTop(T &x){
			if(empty())return false;
			x = data[top-1];
			return true;
		}
};

int main(){
	string str;
	getline(cin,str);
	stack<char> subStr((int)str.length()+5);
	bool flag = false;
	for(int i=0;i<(int)str.length();i++){
		if(str[i]=='@'){
			flag = true;
			continue;
		}
		if(flag){
			char subTop=' ';
			subStr.pop(subTop);
			if(subTop!=str[i]){
				cout<<0<<endl;
				return 0;
			}
		}else{
			subStr.push(str[i]);
		}
	}
	if(flag == false or not subStr.empty()){
		cout<<0<<endl;
	}else{
		cout<<1<<endl;
	}
	 
	return 0;
}

