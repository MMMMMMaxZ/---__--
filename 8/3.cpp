#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+2;
int a[N];

int main(){
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	int n,m;
	cin>>m>>n;
	int len=0;
	while(m!=0){
		a[len++]=m%n;
		m/=n;
	}
	reverse(a,a+len);
	for(int i=0;i<len;i++){
		cout<<a[i]<<' ';
	}
	
	return 0;
}

