#include<iostream>
#include<vector>
using namespace std;

class Graph{
	static const int INF;
	int* fixDay;
	vector<vector<int>> w;
	int n;
	int m;
	public:
		Graph(int n,int m):w(n,vector<int>(n,INF)),n(n),m(m){
			fixDay = new int[n+2];
			for(int i=0;i<n;i++)
				w[i][i]=0;
		}
		void getFixTime(){
			for(int i=0;i<n;i++){
				cin>>fixDay[i];
			}
		}
		void getRoad(){
			int i,j,s;
			for(int k=0;k<m;k++){
				cin>>i>>j>>s;
				w[i][j]=w[j][i]=s;
			}
		}
		void repairNewVil(int t){
			static int idx = 0;//表示i<idx的村庄已重建 
			while(idx<n and fixDay[idx]<=t){
				//idx对应的村庄要开始重建了，添加新的路径
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						w[i][j] = min(w[i][j],w[i][idx]+w[idx][j]);
					}
				} 
				idx++;
			}
		}
		int getW(int i,int j,int t){
			if(fixDay[i]>t or fixDay[j]>t)return -1;
			if(w[i][j]>=INF-1)return -1;
			return w[i][j];
		}
};

const int Graph::INF = 1e4+2;

int main(){
	int n,m;
	cin>>n>>m;
	Graph g(n,m);
	g.getFixTime();
	g.getRoad();
	int Q;cin>>Q;
	while(Q--){
		int x,y,t;
		cin>>x>>y>>t;
		g.repairNewVil(t);
		cout<<g.getW(x,y,t)<<endl;
	}
	return 0;
}

