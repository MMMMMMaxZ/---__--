#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e4+3;
int a[N][N];
int m,n;

int main(){
	cin>>m>>n;
	if(m!=n){
		cout<<"false";
		return 0;
	}else{
		cout<<"true\n";
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
			
	}
	for(int i=0;i<m;i++){
		for(int j=i;j<n;j++){
			swap(a[i][j],a[j][i]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}

