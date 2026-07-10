#include<bits/stdc++.h>
using namespace std;

string ans[]={"NO","YES"};

int main(){
	int n;
	int a,b;
	bool flag = 1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(b==-1)flag=0;
	} 
	cout<<ans[flag]<<endl;
	
	return 0;
}

