#include<iostream>
using namespace std;

int main(){
	freopen("in.txt","r+",stdin);
	int n;
	int adult=1,child0=0,child1=0,child2=0;
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<n;i++){
		adult+=child0;
		child0=child1;
		child1=child2;
		child2=adult;
	}
	cout<<adult+child0+child1+child2;
	
	
	return 0;
}

