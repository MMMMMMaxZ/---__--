#include<bits/stdc++.h>
using namespace std;

bool ishws(string inp){
	int l = 0 , r = inp.length()-1;
	while(l<r){
		if(inp[l]!=inp[r])return false;
		l++;r--;
	}
	return true;
}

string intToStr(int x){
	if(x<0)return "no";
	string str="";
	while(x!=0){
		str+=char((x%10)+'0');
		x/=10;
	}
	if(str.length()==0)return "0";
	return str;
}

int main(){
	freopen("in.txt","r+",stdin);
	int x;
	cin>>x;
	cout<<ishws(intToStr(x))<<endl;
	return 0;
}

