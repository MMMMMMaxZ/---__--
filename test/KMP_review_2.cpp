#include<iostream>
using namespace std;

void getNxtVal(int nxtVal[],string t){
	int l=t.length();
	nxtVal[0]=-1;
	int i=0,j=-1;
	while(i<l){//再加上能数个数的功能吧 
		if(j==-1 or t[i]==t[j]){
			i++;
			j++;
			if(i==l or t[i]!=t[j]){
				nxtVal[i]=j;
			}else{
				nxtVal[i]=nxtVal[j];
			}
		}else{
			j=nxtVal[j];
		}
	}
}

int KMP(string s,string t){
	const int n=s.length(),m=t.length();
	int nxtVal[m+2];
	getNxtVal(nxtVal,t);
	int j=-1,i=-1;
	while(i<n and j<m){
		if(j==-1 or s[i]==t[j]){
			i++;
			j++;
		}else{
			j=nxtVal[j];
		}
	}
	if(j<m)return -1;
	return i-m;
}

int CNT(string s,string t){
	const int n=s.length(),m=t.length();
	int nxtVal[m+2];
	getNxtVal(nxtVal,t);
	int j=-1,i=-1,cnt=0;
	while(i<n and j<m){
		if(j==-1 or s[i]==t[j]){
			i++;
			j++;
			if(j==m){
				cnt++;
				j=nxtVal[j];
			}
		}else{
			j=nxtVal[j];
		}
	}
	return cnt;
}

int main(){
	string s,t;
	cin>>s>>t;
	cout<<KMP(s,t)<<endl;
	cout<<CNT(s,t)<<endl;
	return 0;
}

