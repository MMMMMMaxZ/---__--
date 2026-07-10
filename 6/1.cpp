#include<iostream>
using namespace std;

template<typename T>
class loopQue{
	int maxSize;
	T* data;
	int front,rear;
	public:
		loopQue(int size):maxSize(size){
			data = new T[size];
			front = rear = 0;
		}
		~loopQue(){
			delete[] data;
		}
		bool empty(){return front==rear;}
		int size(){return (rear-front+maxSize)%maxSize;}
		bool push(T e){
			if((rear+1)%maxSize==front)return false;
			rear = (rear+1)%maxSize;
			data[rear] = e;
			return true;
		}
		bool pop(T &e){
			if(empty())return false;
			front = (front+1)%maxSize;
			e = data[front];
			return true;
		}
		bool getHead(T &e){
			if(empty())return false;
			int head = (front+1)%maxSize;
			e = data[head];
			return true;
		}
};

template<typename T>
class stack{
	int maxSize;
	T* data;
	int top;
	public:
		stack(int size):maxSize(size){
			data = new T[size];
			top=-1;
		}
		~stack(){
			delete[] data;
		}
		bool empty(){return top==-1;}
		int size(){return top+1;}
		bool push(T e){
			if(top==maxSize-1)return false;
			data[++top]=e;
			return true;
		}
		bool pop(T &e){
			if(empty())return false;
			e = data[top--];
			return true;
		}
		bool getTop(T &e){
			if(empty())return false;
			e = data[top-1];
			return true;
		}
};

int main(){
	int n;
	cin>>n;
	loopQue<int> q(n+5);
	stack<int> s(n+5);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	for(int i=0;i<n;i++){
		int frt=0;
		q.pop(frt);
		if(frt==-1){
			q.push(-1);
		}else{
			q.push(0);
			s.push(frt);
		}
	}
	for(int i=0;i<n;i++){
		int frt=0;
		q.pop(frt);
		if(frt==-1){
			q.push(-1);
		}else{
			int top=0;
			s.pop(top);
			q.push(top);
		}
	}
	for(int i=0;i<n;i++){
		int x=0;
		q.pop(x);
		cout<<x<<' ';
	}
	
	return 0;
}

