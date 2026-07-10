#include<iostream>
#include<iomanip>
using namespace std;

const int N=15;
int a[N][N];
int n;
int pls[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main(){
	int x=1,y=1,cnt=1,type=0;
	cin>>n;
	for(int i=0;i<=n+1;i++){
		a[i][0]=-1;
		a[i][n+1]=-1;
		a[0][i]=-1;
		a[n+1][i]=-1;
	}
	while(cnt<=n*n){
		a[x][y]=cnt;
		if(a[x+pls[type][0]][y+pls[type][1]]!=0)type=(type+1)%4;
		x=x+pls[type][0];
		y=y+pls[type][1];
		cnt++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<setw(3)<<a[i][j];
		cout<<endl;
	}
	
	return 0;
}

