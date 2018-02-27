#include<stdio.h> 
#include<iostream>
#include<stack>
using namespace std;
typedef int ElemType;
struct BinaryTree{
	ElemType value;
	BinaryTree *left;
	BinaryTree *right;
};
void print(int value){
	printf("%d\n",value);
}
//迭代写法 
void InOrder(BinaryTree *root){
	stack<BinaryTree *>s;
	BinaryTree *bt = root;
	if(root == nullptr)
	    return;
	while(bt!=nullptr || !s.empty()){
		while(bt!=nullptr){
			s.push(bt);
			bt = bt->left;
		}
		if(!s.empty()){
			bt = s.top();
			print(bt->value);
			s.pop();
			bt = bt->right;
		}
	}
}

//递归写法
void InOrder2(BinaryTree *root) {
	if(root == nullptr)
	    return;
	InOrder2(root->left);
	print(root->value);
	InOrder2(root->right);
}

