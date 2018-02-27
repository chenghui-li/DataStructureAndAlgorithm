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
void PreOrder(BinaryTree *root){
	stack<BinaryTree *> s;
	BinaryTree *bt = root;
	if(root == nullptr)
	    return;
	while(bt != nullptr || !s.empty()){
		while(bt!=nullptr){
			print(bt->value);
			s.push(bt);
			bt = bt->left;
		}
		if(!s.empty()){
			bt = s.top();
			s.pop();
			bt = bt->right;
		}
		
	}
}

//递归写法
void PreOrder2(BinaryTree *root) {
	if(root == nullptr)
	    return;
	print(root->value);
	PreOrder2(root->left);
	PreOrder2(root->right);
}
