#include<iostream>
using namespace std;

void getNxtVal(string t,int* nxtVal){
	int k=-1,j=0,m=(int)t.length();
	nxtVal[0]=-1;
	while(j<m){//因为这里需要整体的最长前后等缀 
		if(k==-1 or t[k]==t[j]){
			k++;j++;
			if(j==m or t[k]!=t[j])
				nxtVal[j]=k;
			else
				nxtVal[j]=nxtVal[k];
		}else{
			k=nxtVal[k];
		}
	}
}

int countSubStr(string s,string t){
	int ans=0;
	int n=(int)s.length(),m=(int)t.length();
	int* nxtVal = new int[m+2];
	getNxtVal(t,nxtVal);
	int i=0,j=0;
	while(i<n){
		if(j==-1 or s[i]==t[j]){
			i++;j++;
			if(j==m){
				ans++;
				j=nxtVal[j];
			}
		}else{
			j=nxtVal[j];
		}
	}
	return ans;
}

int main(){
	string t,s;
	getline(cin,t);
	getline(cin>>ws,s);
	cout<<countSubStr(s,t);
	return 0;
}

