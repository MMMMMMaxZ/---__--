#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int get(){
	static char c(' ');
	int x=0;
	while(c==' ' or c=='\n')c=getchar();
	if(c<'0' or c>'9'){ // #
		c = ' '; // 相当于填充了下一位 
		return -1;
	}
	while(c>='0' and c<='9'){
		x = x*10 + c - '0';
		c = getchar();
	}
	return x;
}

class tree{
	int* ftr;
	pair<int,int>* chd;
	int size;
	int root;
	static constexpr int N = 105;
	public:
		tree(int size):size(size),root(-1){
			ftr = new int[N];
			chd = new pair<int,int>[N];
			for(int i=0;i<N;i++)ftr[i]=-1;
		}
		~tree(){
			delete[] ftr;
			delete[] chd;
		}
		void build(){
			for(int i=0;i<size;i++){
				int a,b,c;
				a = get();b=get();c=get();
				if(i==0)root=a;
				if(b!=-1)ftr[b]=a;
				if(c!=-1)ftr[c]=a;
				chd[a]={b,c};
			}
		}
		int longestRoad(){
			pair<int,int> ld1 = getNode(root);
			pair<int,int> ld2 = getNode(ld1.first);
			return ld2.second;
		}
		pair<int,int> getNode(int r){
			bool vis[N];
			memset(vis,0,sizeof(vis));
			int dis = 0, div = r;
			stack<pair<int,int>> stk;
			stk.push({r,0});
			while(not stk.empty()){
				pair<int,int> stp = stk.top();stk.pop();
				int tp = stp.first,d=stp.second;
				//cout<<tp<<' '<<d<<endl;
				if(tp==-1)continue;
				vis[tp]=true;
				int f = ftr[tp],l=chd[tp].first,r=chd[tp].second;
				int stkSize = stk.size();
				if(f!=-1 and not vis[f])stk.push({f,d+1});
				if(l!=-1 and not vis[l])stk.push({l,d+1});
				if(r!=-1 and not vis[r])stk.push({r,d+1});
				if(stkSize==(int)stk.size()){
					if(d>dis){
						dis = d;
						div = tp;
					}
				}
			}
			return {div,dis};
		}
};

int main(){
	int n;
	cin>>n;
	tree tr(n);
	tr.build();
	cout<<tr.longestRoad();
	
	return 0;
}

