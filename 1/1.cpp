#include<bits/stdc++.h>
using namespace std;

const int N=2e4+5,K=2e4;
int n;
int MaxS=-1,MaxK=-1;

int getS(int inp){
	for(int i=2;i*i<=inp;i++){
		if(inp%i==0){
			inp/=i;
			i=1;
		}
	}
	return inp;
}

int main(){
	freopen("in.txt","r+",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		int inp,inpS;
		cin>>inp;
		inpS = getS(inp);
		if(inpS>MaxS){
			MaxS=inpS;
			MaxK=inp;
		}
	}
	cout<<MaxK<<endl;
	return 0;
}

