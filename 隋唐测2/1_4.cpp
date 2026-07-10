#include<iostream>
using namespace std;


struct scNode{
	int d;
	scNode *lft,*rht;
	scNode():lft(nullptr),rht(nullptr){}
	scNode(int dt):d(dt),lft(nullptr),rht(nullptr){}
};


class scTree{
	scNode* root;
	public:
		scTree():root(nullptr){}
		void add(int d){
			if(root==nullptr){
				root = new scNode(d);
				return;
			}
			add(root,d);
		}
		void add(scNode* p,int d){
			if(p==nullptr)return ;
			if(p->d == d)return;
			if(p->d > d){
				if(p->lft==nullptr){
					p->lft = new scNode(d);
				}else{
					add(p->lft,d);
				}
			}
			if(p->d < d){
				if(p->rht==nullptr){
					p->rht = new scNode(d);
				}else{
					add(p->rht,d);
				}
			}
		}
		bool find(int d){
			return find(root,d);
		}
		bool find(scNode* p,int d){
			if(p==nullptr)return false;
			if(p->d==d)return true;
			if(p->d > d)return find(p->lft,d);
			if(p->d < d)return find(p->rht,d);
			return false;
		}
};



int main(){
	return 0;
}

