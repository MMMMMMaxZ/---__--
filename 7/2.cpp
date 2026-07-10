#include<iostream>
using namespace std;

void getNextV(string t,int* nextVal){
	int k=-1,j=0,m=(int)t.length();
	nextVal[0]=-1;
	while(j<m-1){
		if(k==-1 or t[k]==t[j]){
			k++;j++;
			if(t[j]==t[k])
				nextVal[j]=nextVal[k];
			else
				nextVal[j]=k;
		}else{
			k=nextVal[k];
		}
	}
}

int strStr(string s,string t){
	int n=(int)s.length(),m=(int)t.length();
	int* nextVal = new int[m+5];
	getNextV(t,nextVal);
	int i=0,j=0;
	while(i<n and j<m){
		if(j==-1 or s[i]==t[j]){
			i++;j++;
		}else{
			j=nextVal[j];
		}
	}
	if(j>=m)return i-m;
	else return -1;
}

int main(){
	freopen("in.txt","r+",stdin);
	string t,s;
	getline(cin,s);
	getline(cin>>ws,t);
	cout<<strStr(s,t);
	return 0;
}

