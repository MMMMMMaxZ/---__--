#include<bits/stdc++.h>
using namespace std;

void getNextVal(string t,int* nextval){
	int k=-1,j=0;
	nextval[0]=-1;
	while(j<t.length()-1){
		if(k==-1 or t[j]==t[k]){
			k++;j++;
			if(t[j]!=t[k]){
				nextval[j]=k;
			}else{
				nextval[j]=nextval[k];
			}
		}
		else
			k = nextval[k]; // k->最长前后等缀长度 
	}
}

int KMPval(string s,string t){
	int n=s.length(),m=t.length();
	int* nextval = new int[m];
	getNextVal(t,nextval);
	int i=0,j=0;
	while(i<n and j<m){
		if(j==-1 or s[i]==t[j]){
			i++;j++;
		}else{
			j=nextval[j];
		}
	}
	if(j>=m)return i-m;
	else return -1;
}

int main(){
	string a,b;
	cin>>a>>b;
	cout<<KMPval(a,b);
	return 0;
}

