#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find(vector<int>&v,int x){
	int l=0,r=v.size()-1,mid;
	while(l<=r){
		mid = (l+r)>>1;
		if(v[mid]==x)return mid;
		else if(x<v[mid])r=mid-1;
		else l=mid+1;
	}
	return -1;
}

int main(){
	freopen("in.txt","r+",stdin);
	int n,cnt=0;
	vector<int> A,B,C,D,X,Y;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			X.push_back(A[i]+B[j]);
			Y.push_back(C[i]+D[j]);
		}
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	for(int i=0;i<n*n;i++){
		int x=X[i];
		int yi = find(Y,-x);
		if(yi==-1)continue;
		else{
			int l=yi,r=yi;
			while(l>=0 and Y[l]==-x)l--;
			l++;
			while(r<n*n and Y[r]==-x)r++;
			r--;
			cnt+=r-l+1;
		}
	}
	cout<<cnt;
	return 0;
}

