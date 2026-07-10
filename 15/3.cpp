#include<iostream>
using namespace std;

struct Node{
	int key;
	int value;
	Node* nxt;
	Node(int k=0,int v=0):key(k),value(v),nxt(nullptr){}
};

class HashTable{
	Node** table;
	int* len;
	int size;
	int n;
	public:
		HashTable(int n):size(n),n(n){
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
				table[h]=new Node(k,v);
				len[h]++;
				return true;
			}
			else{
				while(p->nxt!=nullptr)p=p->nxt;
				p->nxt = new Node(k,v);
				len[h]++;
				return false;
			}
		}
		bool del(int x){
			int h = x%size;
			Node* p = table[h];
			//cout<<x<<','<<h<<endl;
			if(p==nullptr){
				return false;
			}
			Node* lp = nullptr;
			while(p!=nullptr and p->key!=x){
				lp=p;
				p=p->nxt;
			}
			if(p==nullptr)return false;
			if(lp==nullptr){
				table[h] = p->nxt;
				delete p;
			}else{
				lp->nxt = p->nxt;
				delete p;
			}
			return true;
		}
};

int main(){
	int n;
	cin>>n;
	HashTable HT(5000);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="insert"){
			int k,v;
			cin>>k>>v;
			HT.add(k,v);
		}else{
			int k;
			cin>>k;
			bool s=HT.del(k);
			if(s){
				cout<<"Delete successfully\n";
			}else{
				cout<<"Key not found\n";
			}
		}
		
	}
	return 0;
}

