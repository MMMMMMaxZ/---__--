#include<iostream>
using namespace std;

template<typename T>
struct Node{
	int row;
	int col;
	Node *right,*down;
	union{
		T value;
		Node *link;
	}tag;
};

int main(){
	Node<int> X;
	X.tag.link=&X;
	cout<<X.tag.value<<endl;
	return 0;
}

