#include<iostream>
using namespace std;

class tree{
	pair<char,char>* chd;
	char root;
	int size;
	public:
		tree(int size):root('#'),size(size){
			chd = new pair<char,char>[200];
		}
		void get(){
			char a,b,c;
			for(int i=0;i<size;i++){
				cin>>a>>b>>c;
				if(i==0)root = a;
				chd[(int)a] = {b,c};
			}
		}
		void print(){
			print(root);
		}
		void print(char c){
			if(c=='#')return;
			char l = chd[(int)c].first, r = chd[(int)c].second;
			print(l);
			cout<<c;
			print(r);
		}
};

int main(){
	int n;
	cin>>n;
	tree tr(n);
	tr.get();
	tr.print();
	return 0;
}

