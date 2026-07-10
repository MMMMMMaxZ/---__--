#include<iostream>
using namespace std;

void getNextVal(string t,int* nextVal){
	int k=-1,j=0,m=(int)t.length();
	nextVal[0]=-1;
	while(j<m-1){
		if(k==-1 or t[k]==t[j]){
			k++;j++;
			if(t[k]==t[j])
				nextVal[j]=nextVal[k];
			else
				nextVal[j]=k;
		}else{
			k=nextVal[k];
		}
	}
}

int main(){ 
	freopen("in.txt","r+",stdin);
	string a,b;
	getline(cin,a);
	getline(cin>>ws,b);
	int n=(int)a.length(),m=(int)b.length();
	int *nxtValA = new int[n+2];
	getNextVal(a,nxtValA);
	int k=0,j=0;
	if(n<m)j=m-n;
	while(k<n and j<m){
		if(k==-1 or a[k]==b[j]){
			k++;j++;
		}else{
			k=nxtValA[k];
		}
	}
	//一定是j->m，此时看k即可
	for(int i=0;i<k;i++)cout<<a[i];
	cout<<' '<<k; 
	
	return 0;
}

