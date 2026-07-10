#include<bits/stdc++.h>
using namespace std;

int main(){
	string b="bhello!";
	string c(b);cout<<c<<endl;
	string d(b,1,6);cout<<d<<endl;
	string e(d,2);cout<<e<<endl;
	string f(4,'w');cout<<f<<endl;
	string g("happy");cout<<g<<endl;
	string h;h.assign("hello c++");cout<<h<<endl;
	h.assign(c);cout<<h<<endl;
	
	cout<<endl<<endl;
	string example = "I like lilama";        
	example.pop_back();
	example.append("ama");                   
	example.push_back('!');
	cout << example << endl;                 
	example.erase(15);                       
	example.erase(2, 5);                     
	//字符数组只能使用部分函数，建议直接string 
	// 还可以用“+=”
	//  I like lilamama!
	// 删除15之后的部分 
	// 第二个参数为删除字符个数 
	//string::iterator t = example.begin(); 
	// example.erase(t + 2, t + 7);          
	cout << example << endl;                 
	string in = "am ";
	example.insert(2, in);                   
	//example.insert(t, char);
	cout << example << endl;                 
	example.replace(5, 2, "gay!-------");
	// 此处第二个参数为iterator end，能达到相同效果 
	// I lilamama
	//  在第二个位置插入 
	//  I am lilamama
	//example.replace(it begin, it end, string);
	cout << example << endl;                 
	//  I am gay!
	example.erase();                         
	cout << example << endl;                 
	//  也可以用example.clear() 
	// example 为空
	
	
	return 0;
}

