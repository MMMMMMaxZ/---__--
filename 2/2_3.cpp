#include<bits/stdc++.h>
using namespace std;

int validC[150];
char t=' ';

inline void ini(){
	for(int i='0';i<='9';i++)validC[i]=1;
	validC['-']=2;
	validC['\n']=3;
}

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> cop;
    vector<int> ans;
    for(auto i=nums.begin();i!=nums.end();i++){
        auto k = cop.find(target-*i);
        if( k != cop.end() ){
            ans.push_back(i-nums.begin());
            ans.push_back(k->second);
            return ans;
        }else{
            cop[*i]=i-nums.begin();
        }
    }
    ans.push_back(-1);
	ans.push_back(-1); 
    return ans;
}

typedef pair<int,bool> kk;
inline kk get(){
	while(not validC[(int)t])t=cin.get();
	if(validC[(int)t]==3)
		return{0,0};
	int flg = 1;
	if(validC[(int)t]==2){//-
		flg=-1;
		t=cin.get();
	}
	int rtn = 0;
	
	while(validC[(int)t]==1){
		rtn = rtn*10+(t-'0');
		t=cin.get();
	}
	return {rtn*flg,1};
}

int main(){
	freopen("in.txt","r+",stdin);
	ini();
	kk inp;
	vector<int> a;
	inp=get();
	while(inp.second){
		a.push_back(inp.first);
		inp=get();
	}
	int k;
	cin>>k;
	auto ans = twoSum(a,k);
	cout<<ans[1]<<' '<<ans[0];
	
	
	return 0;
}

