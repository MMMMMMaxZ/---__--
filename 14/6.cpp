#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
	freopen("in.txt","r+",stdin);
	int n;
	vector<int> a;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a.push_back(x);
	}
	priority_queue<int> mn;//mn大根堆 
	priority_queue<int,vector<int>,greater<int>> mx;//小根堆 
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int dt = abs(a[i]-a[j]);
			if(mn.empty() and mx.empty())mn.push(dt);
			else if(mn.empty() and !mx.empty()){
				if(dt<mx.top())mn.push(dt);
				else mx.push(dt);
			}else{//!mn.empty()
				if(dt>mn.top())mx.push(dt);
				else mn.push(dt);
			}
			int Sn = mn.size();
			int Sx = mx.size();
			if(Sn-Sx>1){
				mx.push(mn.top());
				mn.pop();
			}
			if(Sx-Sn>0){
				mn.push(mx.top());
				mx.pop();
			}
		}
	}
	cout<<mn.top();
	return 0;
}

