#include<iostream>
using namespace std;

void st(int a[],int l,int r){
	if(l>=r)return;
	int tmp = a[l];
	int i=l,j=l+1;
	while(j<=r){
		if(a[j]<=tmp){
			a[i++]=a[j];
			if(j>i)a[j]=a[i];
		}
		j++;
	}
	a[i]=tmp;
	st(a,l,i-1);
	st(a,i+1,r);
}

const int N=2e5+2;

int main(){
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	int a[N],t=0;
	int x;
	while(cin>>x){
		a[t++]=x;
	}
	st(a,0,t-1);
	for(int i=0;i<t;i++)
		cout<<a[i]<<' ';
	return 0;
}

