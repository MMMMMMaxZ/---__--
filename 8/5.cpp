#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e3+2;

int main(){
	freopen("in.txt","r+",stdin);
	int n,a[N],cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=i;
	do{
		bool flag = true;
		for(int i=1;flag and i<n;i++){
			for(int j=i+1;flag and j<=n;j++){
				if(abs(a[i]-a[j])==j-i)flag=false;
			}
		}
		if(flag)cnt++;
	}while(next_permutation(a+1,a+n+1));
	cout<<cnt;
	
	return 0;
}
