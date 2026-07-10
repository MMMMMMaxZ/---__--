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
	string t=a+b+"?";
	int tlen = (int)t.length();
	int* nxtVal = new int[tlen+1];
	getNextVal(t,nxtVal);
	int ans = nxtVal[tlen-1];
	ans = min(ans,min(n,m));
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
	cout<<' '<<ans;
	
	return 0;
}

