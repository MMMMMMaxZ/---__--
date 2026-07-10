#include<iostream>
using namespace std;

class heap{
	int* a;
	int size;
	public:
		heap(int n):size(n){
			a=new int[n];
		}
		~heap(){
			delete[] a;
		}
		int get(int i){
			if(i<0 or i>=size)return -1;
			return a[i];
		}
		void shiftDown(int i,int size){
			if(i<0 or i>=size)return;
			int j = i*2+1;
			int tmp = a[i];
			while(j<size){
				if(j<size-1 and a[j]<a[j+1])j++;
				if(tmp<a[j]){
					a[i]=a[j];
					i=j;
					j=i*2+1;
				}else{
					break; 
				}
			}
			a[i]=tmp;
		}
		void sort(){
			int n=size;
			for(int i=n/2-1;i>=0;i--){
				shiftDown(i,size);
			}
			while(n>1){
				swap(a[0],a[n-1]);
				shiftDown(0,n-1);
				n--;
			}
		}
		void print(){
			for(int i=0;i<size;i++)
				cout<<a[i]<<' ';
			cout<<endl;
		}
		void read(){
			for(int i=0;i<size;i++)
				cin>>a[i];
			cout<<endl;
		}
};

int main(){
	int n;
	cin>>n;
	heap hp(n);
	hp.read();
	hp.sort();
	hp.print();
	
	return 0;
}

