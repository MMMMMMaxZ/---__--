#include<iostream>
using namespace std;

class dsu{
	int size;
	int* father;
	int* depth;
	int fCnt;
	public:
		dsu(int size):size(size),fCnt(size){
			father = new int[size];
			depth = new int[size];
			for(int i=0;i<size;i++){
				father[i]=i;
				depth[i]=0;
			}
		}
		int getFather(int x){
			if(father[x]==x)return x;
			else return father[x]=getFather(father[x]);
		}
		void join(int x,int y){
			int fx = getFather(x),fy = getFather(y);
			if(fx==fy)return;
			fCnt--;
			if(depth[x]>depth[y]){
				father[fy]=fx;
			}else{
				if(depth[x]==depth[y])depth[fy]++;
				father[fx]=fy;
			}
		}
		int getFatherCnt(){
			return fCnt;
		}
};

int main(){
	freopen("in.txt","r+",stdin);
	int n,m;
	cin>>n>>m;
	dsu grath(n);
	while(m--){
		int x,y;
		cin>>x>>y;
		grath.join(x,y);
	}
	cout<<grath.getFatherCnt()-1;
	
	return 0;
} 
