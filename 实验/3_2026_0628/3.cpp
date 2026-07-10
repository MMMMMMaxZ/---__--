#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> x){
	for(auto i:x)
		cout<<i<<' ';
	cout<<endl;
}

class Heap{
	vector<int> a;
	void ShiftDown(int i,int r){
		if(i<0 or i>r)return;
		int j=i*2+1;
		while(j<=r){
			if(j+1<=r and a[j+1]>a[j])j++;
			if(a[j]>a[i]){
				swap(a[i],a[j]);
				i=j;
				j=i*2+1;
			}
			else break;
		}
	}
	public:
		Heap(vector<int> n){
			for(auto i:n)a.push_back(i);
			ini();
		}
		vector<int> vec(){
			return a;
		}
		void ini(){
			int n=a.size();
			for(int i=n/2-1;i>=0;i--){
				ShiftDown(i,n-1);
			}
		}
};

vector<int> QuickSort_1(vector<int> a,int l,int r){
	//if(l>=r)return vector<int>(0);
	int tmp = a[l];
	int i=l,j=r;
	while(i<j){
		while(i<j and a[j]>tmp)j--;
		a[i]=a[j];
		while(i<j and a[i]<=tmp)i++;
		a[j]=a[i];
	}
	a[j]=tmp;
	return a;
}

vector<int> BubbleSort_1(vector<int> a){
	int n=a.size();
	for(int i=n-1;i>0;i--){
		if(a[i-1]>a[i])swap(a[i],a[i-1]);
	}
	return a;
}

int main(){
	int n;
	vector<int> a;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	Heap hp(a);
	
	print(hp.vec());
	vector<int> v1 = QuickSort_1(a,0,n-1);
	print(v1);
	print(BubbleSort_1(v1));
	
	return 0;
}

