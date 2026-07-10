#include<iostream>
#include<vector>
using namespace std;

class RK{
	const int base = 131;
	const int mod = 1e9+7;
	string text,pattern;
	vector<long long> pow;
	vector<long long> hash;
	
	public:
		RK(string &a,string &b):text(a),pattern(b){
			int n=text.length();
			pow.resize(n+1);
			hash.resize(n+1);
			pow[0]=1;
			hash[0]=0;
			for(int i=1;i<n;i++){
				pow[i]=pow[i-1]*base % mod;
			}
			for(int i=0;i<n;i++){
				hash[i+1] = (hash[i]*base + (text[i]-'a'+1))%mod;
			}
		}
		long long getText(int l,int r){
			return (hash[r+1] - hash[l]*pow[r-l+1]%mod + mod) % mod;
		}
		long long getPattern(){
			long long ans=0;
			int m=pattern.length();
			for(int i=0;i<m;i++){
				ans = (ans*base + pattern[i]-'a'+1)%mod;
			}
			return ans;
		}
		
		vector<int> search(){
			vector<int> rtn;
			int n=text.length();
			int m=pattern.length();
			if(m>n)return rtn;
			long long ptn = getPattern();
			for(int i=0;i<=n-m;i++){//=
				long long txt = getText(i,i+m-1);
				if(txt!=ptn)continue;
				bool flg = true;
				for(int j=0;j<m;j++){
					if(text[i+j]!=pattern[j]){
						flg=false;
						break;
					}
				}
				if(flg){
					rtn.push_back(i);
				}
			}
			return rtn;
		}
};

int main(){
	string a,b;
	cin>>a>>b;
	RK rk(a,b);
	vector<int> ans;
	ans = rk.search();
	if(ans.empty()){
		cout<<"None";
	}else{
		for(int i:ans){
			cout<<i<<" ";
		}
	}
	return 0;
}

