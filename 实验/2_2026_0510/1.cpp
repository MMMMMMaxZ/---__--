#include<iostream>
using namespace std;

const int N=1e4+2;

class Matrix{
	int *row,*col,*val;
	int m,n,t,p; // 长宽、三元组数量、下一个三元组的下标 
	public:
		Matrix(int m,int n,int t)
		:m(m),n(n),t(t),p(0){
			row = new int[t+2];
			col = new int[t+2];
			val = new int[t+2];
		}
		~Matrix(){
			delete[] row;
			delete[] col;
			delete[] val;
		}
		void get(){
			for(int i=0;i<t;i++){
				int r,c,v;
				cin>>r>>c>>v;
				row[p]=r;
				col[p]=c;
				val[p++]=v;
			}
		}
		Matrix& transposition(){
			int *r,*c,*v;
			r = new int[t];
			c = new int[t];
			v = new int[t];
			int nums[N];
			int pos[N];
			for(int i=0;i<n;i++){
				nums[i]=0;
			}
			for(int i=0;i<t;i++){
				nums[col[i]]++;
			}
			pos[0]=0;
			for(int i=1;i<n;i++){
				pos[i] = pos[i-1]+nums[i-1];
			}
			for(int i=0;i<t;i++){
				r[pos[col[i]]]=col[i];
				c[pos[col[i]]]=row[i];
				v[pos[col[i]]]=val[i];
				pos[col[i]]++;
			}
			swap(row,r);
			swap(col,c);
			swap(val,v);
			delete[] r;
			delete[] c;
			delete[] v;
			swap(m,n);
			return *this;
		}
		void print(){
			cout<<m<<' '<<n<<' '<<t<<endl;
			for(int i=0;i<t;i++){
				cout<<row[i]<<' '<<col[i]<<' '<<val[i]<<endl;
			}
		}
};

int main(){
	freopen("in.txt","r+",stdin);
	freopen("abc.out","w+",stdout);
	int m,n,t;
	cin>>m>>n>>t;
	Matrix M(m,n,t);
	M.get();
	M.transposition();
	M.print();
	return 0;
}

/*
6 7 8
0 1 12
0 2 9
2 0 -3
2 5 14
3 2 24
4 1 18
5 0 15
5 3 -7
*/

