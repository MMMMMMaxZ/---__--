#include<iostream>
using namespace std;

struct Node{
	int value;
	Node* nxt;
	Node(int v=0):value(v),nxt(nullptr){}
};

class HashTable{
	Node** table;
	int* len;
	int size;
	public:
		HashTable(int n):size(n){
			table = new Node*[n];
			len = new int[n];
			for(int i=0;i<n;i++){
				table[i]=nullptr;
				len[i]=0;
			}
		}
		bool add(int k,int v){
			int h = k%size;
			Node* p = table[h];
			//cout<<k<<','<<v<<':'<<h<<endl;
			if(p==nullptr){
				table[h]=new Node(v);
				len[h]++;
				return true;
			}
			else{
				while(p->nxt!=nullptr)p=p->nxt;
				p->nxt = new Node(v);
				len[h]++;
				return false;
			}
		}
		int ASL1(){
			int cnt=0;
			for(int i=0;i<size;i++){
				if(len[i]>0){
					cnt+=(len[i]+1)*(len[i])/2;
				}
			}
			cnt /= (size-1)/2;
			return cnt;
		}
};

int main(){
	int n;
	cin>>n;
	HashTable HT(2*n+1);
	for(int i=0;i<n;i++){
		int k,v;
		cin>>k>>v;
		HT.add(k,v);
	}
	cout<<HT.ASL1();
	return 0;
}

