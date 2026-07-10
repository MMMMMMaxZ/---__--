#include<iostream>
using namespace std;

template<typename T>
class stack{
	public:
		T* data;
		int top,size;
		stack(int MaxSize):size(MaxSize){
			data = new T[MaxSize];
			top = -1;
		}
		~stack(){
			delete[]data;
		}
		bool empty(){
			return top==-1;
		}
		bool push(T a){
			if(top==size-1)return false;
			top++;
			data[top]=a;
			return true;
		}
		bool pop(){
			if(empty())return false;
			top--;
			return false;
		}
		bool pop(T &a){
			if(empty())return false;
			a = data[top--];
			return false;
		}
		bool getTop(T &a){
			if(empty())return false;
			a = data[top];
			return true;
		}
};

const int N=1005;
string inp;
stack<char> sk(N);
char pp[130];//Æ¥Åä£¨×óÀ¨ºÅ->! ; ÓÒÀ¨ºÅ->×óÀ¨ºÅ£© 

int main(){
	pp['(']=pp['[']=pp['{']='!';
	pp[')']='(';
	pp[']']='[';
	pp['}']='{';
	getline(cin,inp);
	for(int i=0;i<(int)inp.length();i++){
		char t = inp[i];
		if(pp[(int)t]=='!')sk.push(t);
		else{
			char tp='i';
			sk.getTop(tp);
			if(pp[(int)t]==tp)sk.pop();
			else{
				cout<<"No\n";
				return 0;
			}
		}
	}
	if(not sk.empty()){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	return 0;
}

