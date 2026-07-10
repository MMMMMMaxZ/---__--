#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class imiQue{
	public:
		imiQue(int memory_size):lft(0),rht(0),empty(1),MaxSize(memory_size){
			lst = new T[memory_size];
		}
		~imiQue(){
			delete[] lst;
		}
		bool push(T x){
			if((rht+1)%MaxSize==lft){
				cout<<"FULL\n";
				return false;
			}
			if(not empty)rht=(rht+1)%MaxSize;
			lst[rht]=x;
			empty=false;
			return true;
		}
		bool front(){
			if(empty){
				cout<<"EMPTY\n";
				return false;
			}
			cout<<lst[lft]<<endl;
			return true;
		}
		bool rear(){
			if(empty){
				cout<<"EMPTY\n";
				return false;
			}
			cout<<lst[rht]<<endl;
			return true;
		}
		bool pop(){
			front();
			if(empty)return false;
			if(lft==rht){
				empty=1;
			}else{
				lft=(lft+1)%MaxSize;
			}
			return true;
		}
		bool getSize(){
			int size = (MaxSize+rht-lft+1)%MaxSize;
			if(empty) size = 0;
			else if(size==0)size=MaxSize;
			cout<<size<<endl;
			return true;
		}
		/*void print(){
			cout<<endl;
			for(int i=0;i<MaxSize;i++)cout<<"------|";cout<<endl;
			for(int i=0;i<MaxSize;i++)cout<<setw(6)<<i<<'|';cout<<endl;
			for(int i=0;i<MaxSize;i++)cout<<setw(6)<<lst[i]<<'|';cout<<endl;
			for(int i=0;i<MaxSize;i++){
				if(i==lft and i==rht)cout<<"l.&&.r|";
				else if(i==lft)cout<<"lft...|";
				else if(i==rht)cout<<"rht...|";
				else cout<<"       ";
			}cout<<endl;
			for(int i=0;i<MaxSize;i++)cout<<"------|";cout<<endl;
		}*/
	private:
		T* lst;
		int lft,rht; // 指向当前左/右端点的索引 
		bool empty;
		int MaxSize;
};

int main(){
	int n,m;
	cin>>n>>m;
	imiQue<int> q(n);
	string inp;
	int x;
	while(m--){
		cin>>ws>>inp;
		if(inp[0]=='E'){
			cin>>x;
			q.push(x);
		}else if(inp[0]=='F'){
			q.front();
		}else if(inp[0]=='R'){
			q.rear();
		}else if(inp[0]=='D'){
			q.pop();
		}else{
			q.getSize();
		}
		//q.print();
	}
	
	return 0;
}

