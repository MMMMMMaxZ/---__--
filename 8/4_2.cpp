#include<iostream>
using namespace std;

const int N=1e4+2;
int a[N];
//f(n)=f(n-1)+f(n-3)
int getAmount(int n){
	if(a[n]!=0)return a[n];
	a[n] = getAmount(n-1)+getAmount(n-3);
	return a[n];
}

int main(){
	freopen("in.txt","r+",stdin);
	int n;
	cin>>n;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	cout<<getAmount(n);
	
	
	
	return 0;
}

