#include<iostream>
#include<map>
#include<queue>
#include<stack>
using namespace std;

const int N=110;
map<int,int> AdToIdx;
int data[N],pd=0,nxt[N],head;
int n;
int tAD,tX,tNX;
queue<int> frt;
stack<int> bck;

void add(int id,int iadd,int inxt){
	AdToIdx[iadd]=pd;
	data[pd]=id;
	nxt[pd++]=inxt;
}

int get(int pls[],int iadd){
	if(iadd==-1)return -1;
	return pls[AdToIdx[iadd]];
}

int main(){
	cin>>head>>n;
	for(int i=0;i<n;i++){
		cin>>tAD>>tX>>tNX;
		add(tX,tAD,tNX);
	}
	for(int i=head,j=0;i!=-1;i=get(nxt,i)){
		if((j++)<(n>>1)){
			frt.push(i);
		}else{
			bck.push(i);
		}
	}
	for(int i=0;i<n-1;i++){
		if(i%2==0){
			printf("%05d %d %05d\n",bck.top(),get(data,bck.top()),frt.front());
			bck.pop();
		}else{
			printf("%05d %d %05d\n",frt.front(),get(data,frt.front()),bck.top());
			frt.pop();
		}
	}
	if(n%2==0){
		printf("%05d %d -1\n",frt.front(),get(data,frt.front()));
		frt.pop();
	}else{
		printf("%05d %d -1\n",bck.top(),get(data,bck.top()));
		bck.pop();
	}
	
	
	
	return 0;
}

