#include<iostream>
#include<sstream>
#include<queue>
using namespace std;

const int N=1e5+2;
int line[N];//表示段数 

int main(){
	string x;
	cin>>x;
	ostringstream os;
	queue<int> output[100];
	int len=(int)x.length(),cnt=0;
	for(int i=0;i<len;i++)line[i]=1;
	for(int i=1;i<len;i++){
		for(int j=0;j<len-i+1;j++){
			if(line[j]<=2){
				cnt++;
				//os<<x.substr(j,i)<<' ';
				output[j].push(i);
				if(j<len-i){
					char k1=x[j+i-1],k2=x[j+i];
					if(k2-k1>1 or k2-k1<0)line[j]++;
				}
			}
		}
	}
	if(line[0]<=2){
		cnt++;
		//os<<x<<' ';
		output[0].push(len);
	}
	for(int j=0;j<len;j++){
		while(not output[j].empty()){
			int i = output[j].front();output[j].pop();
			os<<x.substr(j,i)<<' ';
		}
	}
	cout<<x<<"有"<<cnt<<"个好串："<<os.str();
	
	return 0;
}

