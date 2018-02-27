#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
typedef int ElemType;
typedef struct BinaryTree{
	ElemType value;
	BinaryTree *left;
	BinaryTree *right;
}BinaryTree;
typedef struct Post{
	BinaryTree *ptr;
	int flag;
}Post;
void print(int value){
	printf("%d\n",value);
}

//迭代 
void PostOrder(BinaryTree *root){
	stack<Post>s;
	BinaryTree *bt = root;
	if(root == nullptr)
	    return;
	while(bt != nullptr || !s.empty()){
		while(bt != nullptr){
			Post p;
			p.ptr = bt;
			p.flag = 1;
			s.push(p);
			bt = bt->left;
		}
		while(!s.empty() || s.top().flag == 2){
			bt = s.top().ptr;
			s.pop();
			print(bt->value);
		}
		if(!s.empty()){
			s.top().flag = 2;
			bt = s.top().ptr->right;
		}
	}
}

//递归 
void PostOrder2(BinaryTree *root){
	if(root == nullptr)
	    return;
	PostOrder(root->left);
	PostOrder(root->right);
	print(root->value);
}
