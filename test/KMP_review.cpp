#include<bits/stdc++.h>
using namespace std;

void getNxtVal(string t,int* nxtVal){
	int k=-1,j=0;
	nxtVal[0]=-1;
	while(j<t.length()-1){
		if(k==-1 or t[k]==t[j]){
			k++;j++;
			if(t[k]==t[j]){
				nxtVal[j]=nxtVal[k];
			}else{
				nxtVal[j]=k;
			}
		}else{
			k=nxtVal[k];
		}
	}
}

int KMPval(string s,string t){
	int n=s.length(),m=t.length();
	int* nxtVal = new int[m];
	getNxtVal(t,nxtVal);
	int i=0,j=0,cnt=0;
	while(i<n and j<m){
		cnt++; 
		if(j==-1 or s[i]==t[j]){
			i++;j++;
		}else{
			j=nxtVal[j];
		}
	}
	cout<<"cnt"<<cnt<<endl;
	if(j>=m)return i-m;
	else return -1;
}

void getNxtValCnt(string t,int* nxtVal){
	int k=-1,j=0;
	nxtVal[0]=-1;
	while(j<t.length()){ // j<t.l (-1不要) 
		if(k==-1 or t[k]==t[j]){
			k++;j++;
			if(j==t.length() or t[k]==t[j]){ // j==m
				nxtVal[j]=nxtVal[k];
			}else
				nxtVal[j]=k;
		}else{
			k=nxtVal[k];
		}
	}
}

int KMPcnt(string s,string t){
	int cnt=0;
	int n=s.length(),m=t.length();
	int* nxtVal = new int[m+2];
	getNxtValCnt(t,nxtVal);
	int i=0,j=0;
	while(i<n){ // j<m也可以不要 
		if(j==-1 or s[i]==t[j]){
			i++;j++;
			if(j==m){ // 
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
	string a,b;
	cin>>a>>b;
	KMPval(a,b);
	
	return 0;
}

