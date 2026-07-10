#include<iostream>
#include<stack>
using namespace std;

stack<int> nums;
string input;
int x=0,neg=1;
bool getNum=0;

int main(){
	freopen("in.txt","r+",stdin);
	getline(cin,input);
	for(int i=0;i<(int)input.length();i++){
		int curI = (int)input[i];
		if(curI>='0' and curI<='9'){
			x=x*10+curI-'0';
			getNum = 1;
		}else if(curI=='+'){
			int a=nums.top();
			nums.pop();
			int b=nums.top();
			nums.pop();
			nums.push(a+b);
		}else if(curI=='-'){
			if(i<(int)input.length()-1 and input[i+1]!=','){
				neg=-1;
				continue;
			}
			int a=nums.top();
			nums.pop();
			int b=nums.top();
			nums.pop();
			nums.push(b-a);
		}else if(curI=='*'){
			int a=nums.top();
			nums.pop();
			int b=nums.top();
			nums.pop();
			nums.push(b*a);
		}else if(curI=='/'){
			int a=nums.top();
			nums.pop();
			int b=nums.top();
			nums.pop();
			nums.push(b/a);
		}else{
			if(getNum){
				nums.push(x*neg);
				x=0;
				getNum=0;
				neg=1;
			}
		}
	}
	cout<<nums.top()<<endl;
	nums.pop();
	
	return 0;
}

