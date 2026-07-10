#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>> P_Que;

int main(){
	int n;
	cin>>n;
	while(n--){
		int op;
		cin>>op;
		switch(op){
			case 1:
				int x;
				cin>>x;
				P_Que.push(x);
				break;
			case 2:
				cout<<P_Que.top()<<endl;
				break;
			case 3:
				P_Que.pop();
				break;
		}
	}
	return 0;
}

