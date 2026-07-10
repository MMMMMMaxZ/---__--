#include<iostream>
#include<queue>
using namespace std;

struct scNode{
	int d;
	int td;
	scNode *lft,*rht;
	scNode():td(0),lft(nullptr),rht(nullptr){}
	scNode(int dt):d(dt),td(0),lft(nullptr),rht(nullptr){}
};

class scTree{
	scNode* root;
	public:
		scTree():root(nullptr){}
		void add(int d,int td){
			if(root==nullptr){
				root = new scNode(d);
				root->td = td;
				return;
			}
			add(root,d,td);
		}
		void add(scNode* p,int d,int td){
			if(p==nullptr)return ;
			if(p->d == d)return;
			if(p->d > d){
				if(p->lft==nullptr){
					p->lft = new scNode(d);
					p->lft->td = td;
				}else{
					add(p->lft,d,td);
				}
			}
			if(p->d < d){
				if(p->rht==nullptr){
					p->rht = new scNode(d);
					p->rht->td = td;
				}else{
					add(p->rht,d,td);
				}
			}
		}
		int find(int d){
			return find(root,d);
		}
		int find(scNode* p,int d){
			if(p==nullptr)return 0;
			if(p->d==d)return p->td;
			if(p->d > d)return find(p->lft,d);
			if(p->d < d)return find(p->rht,d);
			return 0;
		}
};

class tree{
	scTree lft,rht;
	int root;
	public:
		tree():root(0){}
		void get(){
			int n;
			char a,b,c;
			cin>>n;
			cin>>a>>b>>c;
			root = a-'0';
			if(b!='#')lft.add(a-'0',b-'0');
			if(c!='#')rht.add(a-'0',c-'0');
			for(int i=1;i<n;i++){
				cin>>a>>b>>c;
				if(b!='#')lft.add(a-'0',b-'0');
				if(c!='#')rht.add(a-'0',c-'0');
			}
		}
		int search(){
			int ans = 0;
			search(root,root,ans);
			return ans;
		}
		void search(int p,int md,int& ans){
			//cout<<p<<' '<<md<<' '<<ans<<endl;
			if(p==0)return;
			md = min(md,p);
			int l=lft.find(p),r=rht.find(p);
			//cout<<":"<<p<<" "<<l<<','<<r<<endl;
			if(l==0 and r==0){
				ans = max(md,ans);
				return;
			}
			search(l,md,ans);
			search(r,md,ans);
		}
		void print(){
			print(root);
		}
		void print(int p){
			if(p==0)return;
			int l=lft.find(p),r=rht.find(p);
			cout<<p<<' ';
			print(l);
			print(r);
		}
};

/*
5
3 2 4
2 # #
1 # #
6 1 #
4 6 #
*/

int main(){
	tree bt;
	bt.get();
	//bt.print();cout<<endl;
	cout<<bt.search();

	return 0;
}

