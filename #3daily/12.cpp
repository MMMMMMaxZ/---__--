#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> a;
	int T;
	string inp;
	cin>>T;
	while(T--){
		getline(cin>>ws,inp);
		int n=(int)inp.length();
		if(inp[0]=='I'){
			int x=0,fst=0;bool getNum=false;
			for(int i=7;i<n;i++){
				char ch = inp[i];
				if(ch==' '){
					getNum=true;
					fst=x;
					x=0;
				}else{
					x = x*10+ch-'0';
				}
			}
			if(getNum){//insert k(fst) x(x)
				a.insert(a.begin()+fst-1,x);
			}else{
				a.push_back(x);
			}
			
		}else if(inp[0]=='D'){
			int x=0;
			for(int i=7;i<n;i++){
				char ch = inp[i];
				x = x*10+ch-'0';
			}
			a.erase(a.begin()+x);
		}else{//FIND
			int x=0;
			for(int i=5;i<n;i++){
				char ch = inp[i];
				x = x*10+ch-'0';
			}
			auto t = find(a.begin(),a.end(),x);
			if(t==a.end()){
				cout<<-1<<endl;
			}else{
				cout<<t-a.begin()+1<<endl;
			}
		}
	}
	return 0;
}

