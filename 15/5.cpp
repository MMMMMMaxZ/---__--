#include<iostream>
using namespace std;

void st(int a[],int n,int d){
	if(d<=0)return;
	for(int s=0;s<d;s++){
		int i=0;
		while(i<n){
			if(i+d>=n)break;
			int tmp=a[i+d];
			int j=i;
			while(j>=s and a[j]>tmp){
				a[j+d]=a[j];
				j-=d;
			}
			a[j+d]=tmp;
			i+=d;
		}
	}
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
	int d=t/2;
	while(d>0){
		st(a,t,d);
		d/=2;
	}
	for(int i=0;i<t;i++)
		cout<<a[i]<<' ';
	return 0;
}

