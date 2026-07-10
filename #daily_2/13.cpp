#include<iostream>
using namespace std;

class UF{
	int size;
	int *fth;
	int *rk;
	int *amt;
	public:
		UF(int n):size(n){
			fth = new int[n];
			rk = new int[n];
			amt = new int[n];
			for(int i=0;i<n;i++){
				fth[i]=i;
				rk[i]=1;
				amt[i]=1;
			}
		}
		int getAmt(int x){//
			return amt[x];
		}
		int query(int x){
			if(fth[x]==x)return x;
			else return fth[x]=query(fth[x]);
		}
		bool same(int x,int y){
			int fx = query(x);
			int fy = query(y);
			return fx==fy;
		}
		bool union_(int x,int y){
			int fx = query(x);
			int fy = query(y);
			if(fx==fy)return false;
			int rx = rk[fx],ry = rk[fy];
			if(rx<ry){
				fth[fx]=fy;
				amt[fy]+=amt[fx];
			}else if(rx>ry){
				fth[fy]=fx;
				amt[fx]+=amt[fy];
			}else{
				fth[fy]=fx;
				amt[fx]+=amt[fy];
				rk[fx]++;
			}
			return true;
		}
};

int main(){
	int n,m,x,y;
	string s;
	cin>>n>>m;
	UF uf(n+2);
	for(int i=0;i<m;i++){
		cin>>s;
		if(s=="union"){
			cin>>x>>y;
			uf.union_(x,y);
		}else if(s=="query"){
			cin>>x;
			int f = uf.query(x);
			cout<<f<<' '<<uf.getAmt(f)<<endl;
		}else{
			cin>>x>>y;
			bool s = uf.same(x,y);
			if(s)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

