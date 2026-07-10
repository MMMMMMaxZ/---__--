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
			cout<<"in ";
			return true;
		}
		bool pop(T &x){
			if(empty())return false;
			x = data[top--];
			cout<<"out ";
			return true;
		}
		bool getTop(T &x){
			if(empty())return false;
			x = data[top-1];
			return true;
		}
};

template<typename T>
class queue{
	T* data;
	int front,rear;
	int maxSize;
	public:
		queue(int size):maxSize(size){
			data = new T[size];
			front = 0;
			rear = 0;
		}
		~queue(){
			delete[] data;
		}
		bool empty(){
			return front==rear;
		}
		bool push(T x){
			if((rear+1)%maxSize==front)return false;
			rear = (rear+1)%maxSize;
			data[rear]=x;
			return true;
		}
		bool pop(T &x){
			if(empty())return false;
			front = (front+1)%maxSize;
			x = data[front];
			return true;
		}
		bool getFront(T &x){
			if(empty())return false;
			x = data[(front+1)%maxSize];
			return true;
		}
};

const int N=1e5;
int n;
stack<int> stk(N);
queue<int> ans(N);

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		stk.push(x);
		if(x%2==1){
			int top=0;
			stk.pop(top);
			ans.push(top);
		}
	}
	while(not stk.empty()){
		int top=0;
		stk.pop(top);
		ans.push(top);
	}
	cout<<endl;
	while(not ans.empty()){
		int frt=0;
		ans.pop(frt);
		cout<<frt<<' ';
	}
	
	return 0;
}

