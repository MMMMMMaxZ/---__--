#include<iostream>
#include<queue>
using namespace std;

const int N=1e4;
int ans[N];
queue<int> idx;
int n;

int main(){
	cin>>n;
	for(int i=0;i<n;i++)idx.push(i);
	int output = 1;
	while(not idx.empty()){
		int top = idx.front();
		idx.pop();
		idx.push(top);
		top = idx.front();
		ans[idx.front()]=output++;
		idx.pop();
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<' ';
	return 0;
}

