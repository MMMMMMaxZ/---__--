#include<iostream>
#include<vector>
using namespace std;

const int maxV = 1e4+2;

typedef struct{
	int numberVertices, numEdges;
	char VerticesList[maxV];
	int edge[maxV][maxV];
}MG;

MG MGraph;

int getI(char x){
	for(int i=0;i<MGraph.numberVertices;i++)
		if(MGraph.VerticesList[i]==x)return i;
	return -1;
}

int main(){
	string inp;
	int n=0,m=0;
	getline(cin,inp);
	int len = inp.length();
	for(int i=0;i<len;i++){
		if(inp[i]=='{' or inp[i]=='}' or inp[i]==',')continue;
		MGraph.VerticesList[n++]=inp[i];
	}
	MGraph.numberVertices = n;
	char lft = '\0';
	getline(cin,inp);
	len = inp.length();
	for(int i=0;i<len;i++){
		if(inp[i]=='(' or inp[i]==')' or inp[i]==',')continue;
		if(lft=='\0')lft=inp[i];
		else{
			int Li=getI(lft),Ri=getI(inp[i]);//默认一定存在
			MGraph.edge[Li][Ri]=1;
			m++; 
			lft='\0';
		}
	}
	MGraph.numEdges=m;
	
	vector<char> Kv;
	for(int i=0;i<n;i++){
		int in=0,ot=0;
		for(int j=0;j<n;j++){
			if(MGraph.edge[i][j]==1)ot++;
			if(MGraph.edge[j][i]==1)in++;
		}
		if(ot>in)Kv.push_back(MGraph.VerticesList[i]);
	}
	cout<<"K vertices:";
	for(auto i:Kv)cout<<' '<<i;
	cout<<endl;
	cout<<"Number of K vertices: "<<Kv.size();
	
	return 0;
}

