#include<iostream>
using namespace std;

template<typename T>
class Queue{
	T* data;
	int front;
	int rear;
	int MaxSize;
	public:
		Queue(int size):MaxSize(size){
			data = new T[size];
			front=rear=0;
		}
		~Queue(){
			delete[] data;
		}
		bool isEmpty(){
			return front==rear;
		}
		bool isFull(){
			return ((rear+1)%MaxSize)==front;
		}
		bool enqueue(T x){
			if(isFull())return false;
			rear = (rear+1)%MaxSize;
			data[rear] = x;
			return true;
		}
		bool dequeue(T &x){
			if(isEmpty())return false;
			front = (front+1)%MaxSize;
			x = data[front];
			return true;
		}
		bool getFront(T &x){
			if(isEmpty())return false;
			int ft = (front+1)%MaxSize;
			x = data[ft];
			return true;
		}
		int size(){
			return (rear-front+MaxSize)%MaxSize;
		}
};

int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	Queue<int> up(n),dw(n);
	if(n%2==0){
		for(int i=1;i<=n/2;i++)up.enqueue(i);
		for(int i=n/2+1;i<=n;i++)dw.enqueue(i);
		while(!up.isEmpty() and !dw.isEmpty()){
			int x=0;
			up.dequeue(x);cout<<x<<' ';
			dw.dequeue(x);cout<<x<<' ';
		}
	}else{
		for(int i=1;i<=(n+1)/2;i++)up.enqueue(i);
		for(int i=(n+1)/2+1;i<=n;i++)dw.enqueue(i);
		int x=0;
		up.dequeue(x);cout<<x<<' ';
		while(!up.isEmpty() and !dw.isEmpty()){
			int x=0;
			dw.dequeue(x);cout<<x<<' ';
			up.dequeue(x);cout<<x<<' ';
		}
	}
	
	return 0;
}

