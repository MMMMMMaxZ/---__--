#include<iostream>
#include<algorithm>
using namespace std;

//对于每个a，二分法找最近的b,c，然后组合去看谁最小
const int N=1e4+5,INF=1e7+2;
int s1[N],s2[N],s3[N];
int n,m,k;
int ans=INF;

int getD(int a,int b,int c){
	return abs(a-b)+abs(a-c)+abs(b-c);
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>s1[i];
	for(int i=0;i<m;i++)cin>>s2[i];
	for(int i=0;i<k;i++)cin>>s3[i];
	sort(s1,s1+n);
	sort(s2,s2+m);
	sort(s3,s3+k);
	
	for(int i=0;i<n;i++){
		int a=s1[i],b1,b2,c1,c2;
		int *ib = lower_bound(s2,s2+m,a);
		if(ib==s2+m)b1=b2=s2[m-1];
		else if(ib==s2)b1=b2=s2[0];
		else{
			b1=*(ib-1);
			b2=*ib;
		}
		int *ic = lower_bound(s3,s3+k,a);
		if(ic==s3+k)c1=c2=s3[k-1];
		else if(ic==s3)c1=c2=s3[0];
		else{
			c1=*(ic-1);
			c2=*ic;
		}
		ans=min(ans,getD(a,b1,c1));
		ans=min(ans,getD(a,b1,c2));
		ans=min(ans,getD(a,b2,c1));
		ans=min(ans,getD(a,b2,c2));
	}
	cout<<ans<<endl;
	
	return 0;
}

