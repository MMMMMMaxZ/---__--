#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

const int N = 1e5+5;

int main(){
	freopen("in.txt","r+",stdin);
	
	string input;
	getline(cin,input);
	istringstream iss(input);
	
	char ch;
	char a[N];
	int p=0;
	while(iss>>ch){
		a[p++]=ch;
	}
	int i=0,j=0,k=0;
	while(j<p){
		if(a[i]==a[j])
			j++;
		else{
			if(j-i==1){
				a[k]=a[i];
				k++;
				i=j;
			}else{
				a[k]=a[i];
				int t=j-i,p=k;
				while(t!=0){
					a[++p]=(char)t%10+'0';
					t/=10;
				}
				reverse(a+k+1,a+p+1);
				k=p+1;
				i=j;
			}
		}
	}
	if(j-i==1){
		a[k]=a[i];
		k++;
		i=j;
	}else{
		a[k]=a[i];
		int t=j-i,p=k;
		while(t!=0){
			a[++p]=(char)t%10+'0';
			t/=10;
		}
		reverse(a+k+1,a+p+1);
		k=p+1;
		i=j;
	}
	for(int o=0;o<k;o++){
		cout<<(char)a[o];
		if(o<k-1)cout<<' ';
	}
	
	
	return 0;
}

