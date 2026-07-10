#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

const int N=1e4+2;
map<string,int> cnt;

int main(){
	freopen("in.txt","r+",stdin);
	string s;
	int all=0;
	while(getline(cin,s)){
		if(cnt.find(s)==cnt.end()){
			cnt.insert({s,1});
		}else{
			cnt[s]++;
		}
		all++;
	}
	for(auto i:cnt){
		string name = i.first;
		int amt = i.second;
		double p = (double)amt*100.0 / all;
		cout<<name<<' '<<fixed<<setprecision(4)<<p<<endl;
	}
	
	return 0;
}

