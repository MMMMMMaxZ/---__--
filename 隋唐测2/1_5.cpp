#include<iostream>
#include<stack>
using namespace std;

const int N = 103;

struct Node{
	int d;
	Node *lft,*rht;
	Node():lft(nullptr),rht(nullptr){}
	Node(int dt):d(dt),lft(nullptr),rht(nullptr){}
};

class Pipe{
	int root;
	pair<int,int>* chd;
	Node* rtNode;
	public:
		Pipe():rtNode(nullptr){
			chd = new pair<int,int>[N];
		}
		void get(){
			int n;
			cin>>n;
			char a,b,c;
			cin>>a>>b>>c;
			root = a-'0';
			chd[root].first = (b=='#')?-1:(b-'0');
			chd[root].second = (c=='#')?-1:(c-'0');
			for(int i=1;i<n;i++){
				cin>>a>>b>>c;
				chd[(a-'0')].first = (b=='#')?-1:(b-'0');
				chd[(a-'0')].second = (c=='#')?-1:(c-'0');
			}
		}
		int build(){
			int ans=0;
			rtNode = new Node(root);
			stack<pair<Node*,int>> stk;
			stk.push({rtNode,root});
			while(not stk.empty()){
				auto tp = stk.top();stk.pop();
				Node* p = tp.first;
				int md = tp.second;
				if(md<ans)continue;
				int l = chd[p->d].first, r = chd[p->d].second;
				if(l==-1 and r==-1){
					ans = max(ans,md);
				}else{
					if(l!=-1){
						p->lft = new Node(l);
						if(min(l,md)>ans)stk.push({p->lft,min(md,l)});
					}
					if(r!=-1){
						p->rht = new Node(r);
						if(min(r,md)>ans)stk.push({p->rht,min(md,r)});
					}
				}
			}
			return ans;
		}
};

int main(){
	Pipe pp;
	pp.get();
	cout<<pp.build();
	return 0;
}
/*

50	49	#
49	48	#
48	47	#
47	46	#
46	45	#
45	44	#
44	43	#
43	42	#
42	41	#
41	40	#
40	39	#
39	38	#
38	37	#
37	36	#
36	35	#
35	34	#
34	33	#
33	32	#
32	31	#
31	30	#
30	29	#
29	28	#
28	27	#
27	26	#
26	25	#
25	24	#
24	23	#
23	22	#
22	21	#
21	20	#
20	19	#
19	18	#
18	17	#
17	16	#
16	15	#
15	14	#
14	13	#
13	12	#
12	11	#
11	10	#
10	9	#
9	8	#
8	7	#
7	6	#
6	5	#
5	4	#
4	3	#
3	2	#
2	1	#
1	#	#


*/
