#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

short int level[128];
void ini(){
	level['*']=level['/']=2;
	level['+']=level['-']=1;
	level['(']=level[')']=0;
}

//把字母视为数字（x-'a'）便可丢入计算 // 更严谨的话应该把'z'-x+1再丢进去算一次 
string getPostfix(string input){
	int len = (int)input.length();
	ostringstream out;
	stack<char> operators;
	int x=0;
	bool getNum=false,isNegative = false;
	for(int i=0;i<len;i++){
		char t = input[i];
		if((t>='a' and t<='z')or(t>='A' and t<'Z')){
			if(isNegative or getNum)return "%1Error";
			x=(int)t;
			getNum=true;
		}else if(t>='0' and t<='9'){//数字 
			x=x*10+t-'0';
			getNum=true;
		}else if(t=='-' and (i==0 or input[i-1]=='(')){
			isNegative = true;
		}else{ // 运算符 
			if(getNum){
				if(isNegative)x*=-1;
				out<<'#'<<x;
				x=0;
				getNum=false,isNegative = false;
			}
			if(operators.empty() or t=='('){
				operators.push(t);
			}else if(t==')'){
				bool find=false;
				while(!operators.empty()){
					char top = operators.top();
					operators.pop();
					if(top=='('){
						find = true;
						break;
					}
					out<<top;
				}
				if(not find)return "%2Error";
			}else{//+-*/
				if(i==0)return "%3Error";
				char top = operators.top();
				if(i!=0 and level[(int)input[i-1]]>0){//+-*/连着
					return "%4Error";
				}
				if(top=='(' or level[(int)top]<level[(int)t]){
					operators.push(t);
				}else{//top>=t
					while(!operators.empty()){
						char top = operators.top();
						operators.pop();
						if(top=='(' or level[(int)top]<level[(int)t]){
							operators.push(top);
							break;
						}
						out<<top;
					}
					operators.push(t);
				}
			}
		}
	}
	if(getNum){
		if(isNegative)x*=-1;
		out<<'#'<<x;
		x=0;
		getNum=false,isNegative = false;
	}
	while(not operators.empty()){
		char top = operators.top();
		operators.pop();
		if(top=='(')return "%5Error";
		out<<top;
	}
	return out.str();
}

int calculate(string input){
	int len=input.length();
	stack<int> nums;
	for(int i=0;i<len;i++){
		char t=input[i];
		if(t=='#'){
			int x=0;bool isNegative = false;
			if(input[++i]=='-'){
				isNegative = true;
				i++;
			}
			while(input[i]>='0' and input[i]<='9'){
				x=x*10+input[i]-'0';
				i++;
			}
			i--;
			if(isNegative)x*=-1;
			nums.push(x);
		}else{
			if(nums.size()<2)return -9999999;
			int x1 = nums.top();nums.pop();
			int x2 = nums.top();nums.pop();
			if(t=='+')
				nums.push(x2+x1);
			else if(t=='-')
				nums.push(x2-x1);
			else if(t=='*')
				nums.push(x2*x1);
			else if(t=='/' and x1!=0)
				nums.push(x2/x1);
			else
				return -9999990;
		}
	}
	if(nums.size()!=1)return -9999999;
	return nums.top();
}

int main(){
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
	ini();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		/*string a;
		getline(cin>>ws,a);
		string o1(getPostfix(a));
		cout<<o1<<endl;
		if(o1[0]!='%'){
			cout<<calculate(o1)<<endl;
		}*/
		cout<<"测试用例"<<i<<"：";
		string a1,a2;
		short int error1 = 0,error2=0;
		getline(cin>>ws,a1);
		getline(cin>>ws,a2);
		string o1(getPostfix(a1));
		if(o1[0]=='%'){
			error1 = 1;
		}
		string o2(getPostfix(a2));
		if(o2[0]=='%'){
			error2 = 1;
		}
		int n1 = calculate(o1);
		int n2 = calculate(o2);
		if(error1==0 and n1==-9999999){
			error1 = 1;
		}else if(error1==0 and n1==-9999990){
			error1 = 2;
		}
		if(error2==0 and n2==-9999999){
			error2 = 1;
		}else if(error2==0 and n2==-9999990){
			error2 = 2;
		}
		
		
		if(error1==1)cout<<"表达式1无效！";
		else if(error1==2)cout<<"表达式1除0出错！";
		if(error2==1)cout<<"表达式2无效！";
		else if(error2==2)cout<<"表达式2除0出错！";
		if(error1==0 and error2==0){
			if(n1==n2){
				cout<<"TRUE";
			}else{
				cout<<"FALSE";
			}
		}
		cout<<endl;
	}
	
	return 0;
}

