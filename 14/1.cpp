#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e5+2;

class Graph{
	int size;
	vector<vector<pair<int,int>>> Edge;
	public:
		Graph(int n):size(n),Edge(size+2,vector<pair<int,int>>()){}
		void getEdge(){
			for(int i=1;i<=size;i++){
				int m;
				cin>>m;
				for(int j=0;j<m;j++){
					int x,w;
					cin>>x>>w;
					Edge[i].push_back({w,x});
				}
			}
		}
		int getGT(int x){//以x为起点 
			int maxT=-1;
			int getTime[size+2];
			for(int i=1;i<=size;i++){
				getTime[i]=INF;
			}
			getTime[x]=0;
			queue<int> q;
			q.push(x);
			while(!q.empty()){
				int tp = q.front();q.pop();
				int curT = getTime[tp];
				for(auto i:Edge[tp]){
					int w = i.first,v=i.second;
					if(curT+w<getTime[v]){
						getTime[v]=curT+w;
						q.push(v);
					}
				}
			}
			for(int i=1;i<=size;i++){
				if(getTime[i]>=INF-20)return -1;
				maxT = max(maxT,getTime[i]);
			}
			return maxT;
		}
		void solution(){
			int minT = INF,K=-1;
			for(int i=1;i<=size;i++){
				int ans = getGT(i);
				if(ans==-1)continue;
				if(ans<minT){
					minT=ans;
					K=i;
				}
			}
			if(K==-1){
				cout<<"disjoint\n";
			}else{
				cout<<K<<' '<<minT<<endl;
			}
		}
};

int main(){
	freopen("in.txt","r+",stdin);
	int n;
	cin>>n;
	Graph G(n);
	G.getEdge();
	G.solution();
	return 0;
}

