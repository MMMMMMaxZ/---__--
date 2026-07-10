#include<iostream>
using namespace std;

const int N=2e4+2;
string s[N];
int sz=0;

int main(){
	freopen("in.txt","r+",stdin);
	string str;
	getline(cin,str);
	while(str!="9"){
		s[sz++]=str;
		getline(cin>>ws,str);
	}
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			if(i==j)continue;
			string s1=s[i],s2=s[j];
			if(s1.length()>s2.length())continue;
			int l1 = s1.length(),i;
			for(i=0;i<l1;i++){
				if(s1[i]!=s2[i]){
					break;
				}
			}
			if(i==l1){
				cout<<"N";
				return 0;
			}
		}
	}
	cout<<"Y";
	
	return 0;
}

