#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+5;
int n;
int speed[N];//Si
priority_queue<pair<int,int>>rank_list;//first->s,second->id*(-1) [´ó¸ù¶ÑÐ¡±àºÅ]
queue<pair<int,int>> operate_queue;

inline void refresh(){
	while(not rank_list.empty()){
		operate_queue.push(rank_list.top());
		rank_list.pop();
	}
	while(not operate_queue.empty()){
		auto player = operate_queue.front();
		player.first += speed[player.second*(-1)];
		rank_list.push(player);
		operate_queue.pop();
	}
}

int main(){
	freopen("in.txt","r+",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		int f,s;
		cin>>f>>s;
		speed[i]=s;
		rank_list.push({f,i*(-1)});
	}
	while(not rank_list.empty()){
		auto player = rank_list.top();
		cout<<player.second*(-1)<<' ';
		rank_list.pop();
		refresh();
	}
	return 0;
}

