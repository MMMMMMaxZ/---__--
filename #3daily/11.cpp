#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int data;
	Node* lft,* rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(int d):data(d),lft(nullptr),rht(nullptr){}
	~Node(){
		if(lft!=nullptr)delete lft;
		if(rht!=nullptr)delete rht;
	}
};

class tree_set{
	Node* father;
	public:
		tree_set():father(nullptr){
		}
		~tree_set(){
			delete father;
		}
		bool add(Node* &p,int x){
			if(p == nullptr){
				p = new Node(x);
				return true;
			}
			if(p->data==x)return false;
			else{
				if(p->data>x){
					return add(p->rht,x);
				}else{
					return add(p->lft,x);
				}
			}
		}
		bool add(int x){
			return add(father,x);
		}
};

int main(){
	int n,x;
	tree_set nums;
	vector<int> ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		bool exst = nums.add(x);
		if(exst)ans.push_back(x);
	}
	for(auto i:ans){
		cout<< i <<' ';
	}
	return 0;
}

