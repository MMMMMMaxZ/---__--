#include<iostream>
using namespace std;

int main(){
	string a;
	getline(cin,a);
	int len=(int)a.length();
	int maxSubLen = 0;
	char lt=a[0],lstLetter=a[0],l=1;
	for(int i=1;i<len;i++){
		char ch = a[i];
		if(ch==lstLetter){
			l++;
		}else{
			if(l>maxSubLen and l>1){
				maxSubLen = l;
				lt = lstLetter;
			}
			lstLetter = ch;
			l=1;
		}
	}
	if(l>maxSubLen and l>1){
		maxSubLen = l;
		lt = lstLetter;
	}
	for(int i=0;i<maxSubLen;i++)cout<<lt;
	return 0;
}

