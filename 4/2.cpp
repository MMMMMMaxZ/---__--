#include<iostream>
#include<stack> 
using namespace std;

/*
但是这个算法有个问题 
如:
a b p a q
b a q p a 
会输出false，
但实际上（若记入栈是操作1，出栈是操作2）
1121121222可以实现 baqpa 的 
*/ 

const int N = 30;
int n,outputIdx = 0,inputIdx=0;
char input[N],ans[N];
stack<char> checkSt;
bool eq = true;
string output[2]={"false","true"};

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>input[i];
	for(int i=0;i<n;i++)
		cin>>ans[i];
	while(outputIdx<n){
		if(checkSt.empty()){
			checkSt.push(input[inputIdx]);
			inputIdx++;
		}else if(checkSt.top()==ans[outputIdx]){
			checkSt.pop();
			outputIdx++;
		}else if(inputIdx<n){
			checkSt.push(input[inputIdx]);
			inputIdx++;
		}else{
			eq = false;
			break;
		}
	}
	cout<<output[eq];
	
	return 0;
}

