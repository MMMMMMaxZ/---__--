#include<bits/stdc++.h>
using namespace std;

const int N=1e5+3;
int data[N]={0},nxt[N]={0},pd=1;
int n;
int td,tn;
string ans[]={"NO","YES"};

void add(int d,int nx){
	if(nx==-1)nx=0; // 将-1定义为0就不会溢出了 
	data[pd]=d;
	nxt[pd++]=nx;
}

bool checkNotCircle(){
	int i=1,j=1;
	do{
		i=nxt[i];
		j=nxt[nxt[j]];
		cout<<i<<' '<<j<<endl;
	}while(i!=0 and j!=0 and i!=j);
	if(i==j and i!=0)return true;
	return false;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>td>>tn;
		add(td,tn);
	}
	cout<<ans[checkNotCircle()]<<endl;
	
	return 0;
}

