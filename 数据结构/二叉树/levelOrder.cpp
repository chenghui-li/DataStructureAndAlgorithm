#include<iostream>
#include<stdio.h>
#include<queue>
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
void levelOrder(BinaryTree *root){
	queue<BinaryTree *> q;
	BinaryTree *bt = root;
	if(root == nullptr)
	    return;
	q.push(root);
	while(!q.empty()){
		bt = q.front();
		print(bt->value);
		q.pop();
		if(bt->left != nullptr)
		    q.push(bt->left);
		if(bt->right != nullptr)
		    q.push(bt->right);
	} 
}
