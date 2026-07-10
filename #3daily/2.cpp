#include<iostream>
#include<stack>
using namespace std;

stack<int> a,b;
int mx=0,n,x;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		a.push(x);
	}
	for(int i=n;i>0;i--){
		mx=0;
		for(int j=0;j<i;j++){
			int tp = a.top();
			mx = max(mx,tp);
			a.pop();
			b.push(tp);
		}
		bool flg = 0;
		for(int j=0;j<i;j++){
			int tp = b.top();
			b.pop();
			if(tp!=mx or flg)a.push(tp);
			if(tp==mx)flg=1;
		}
		b.push(mx);
	}
	while(not b.empty()){
		cout<<b.top()<<' ';
		b.pop();
	}
	return 0;
}

