#include<iostream>
#include<queue>
using namespace std;

bool checked[12][12]; // 2~9为实际使用棋盘，多的两格宽是边界 
struct Node{
	int x,y;
	int step;
	Node operator+(Node &p){
		return Node{x+p.x,y+p.y,step+p.step};
	}
	bool operator==(Node &p){
		return (x==p.x and y==p.y);
	}
};
Node jump[8]={
	{-1,2,1},{1,2,1},
	{-2,1,1},{-2,-1,1},
	{-1,-2,1},{1,-2,1},
	{2,1,1},{2,-1,1}
};
Node getCoordination(){
	char x;int y;
	cin>>ws>>x>>y;
	return Node{x-'a'+2,y+1,0};
}
inline void setBorder(){
	for(int i=0;i<12;i++){
		checked[i][0]=true;
		checked[i][1]=true;
		checked[i][10]=true;
		checked[i][11]=true;
		checked[0][i]=true;
		checked[1][i]=true;
		checked[10][i]=true;
		checked[11][i]=true;
	}
}
Node Start,End;
queue<Node> searchQue;
int ans=-1;

int main(){
	Start = getCoordination();
	End = getCoordination();
	if(Start == End)ans=0;
	setBorder();
	checked[Start.x][Start.y]=true;
	searchQue.push(Start);
	while(not searchQue.empty() and ans==-1){
		Node top = searchQue.front();
		searchQue.pop();
		for(int i=0;i<8;i++){
			Node nxt = top + jump[i];
			if(checked[nxt.x][nxt.y])continue;
			else if(nxt == End){
				ans = nxt.step;
				break;
			}else{
				checked[nxt.x][nxt.y]=true;
				searchQue.push(nxt);
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}

