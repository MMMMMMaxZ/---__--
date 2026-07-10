#include<bits/stdc++.h>
using namespace std;

void getNextVal(string t,int* nextVal){
	int k=-1,j=0;
	nextVal[0]=-1;
	while(j<t.length()-1){//因为判断时j是当前的前一位，故-1 
		if(k==-1 or t[k]==t[j]){
			k++;j++;
			if(t[k]!=t[j])
				nextVal[j]=k;//记录前面最长子串长度 
			else
				nextVal[j]=nextVal[k];//如果相等时，回溯到起点。 
		}else{
			k=nextVal[k];//k回溯 
		}
	}
}

int KMP(string s,string t){
	int i=0,j=0;
	const int L = t.length();
	int* nextVal = new int[L+4];
	getNextVal(t,nextVal);
	while(i<s.length() and j<t.length()){
		if(j==-1 or s[i]==t[j]){
			i++;j++;
		}else{
			j=nextVal[j];
		}
	}
	if(j==t.length()){ // j>=m ?什么情况下j>m 
		return i-j; // i-m
	}else{
		return -1;
	}
}

int main(){
	return 0;
}

