#include<iostream>
using namespace std;
class List
{
public:
	List();
	int front();
	int back();
	void push_back(int elem);
	void pop_back();
	void push_front(int elem);
	void pop_front();
	void traverse(); 
	bool insert_before(int elem1,int elem2);	//在elem1元素前插入elem2元素
	bool insert_after(int elem1,int elem2);
	bool empty();
	int size();
	bool remove(int elem);
	//~List();
private:
	struct node
	{
		int data;
		struct node *next;
		struct node *pre;
	};
	int length;
	struct node *head;
	
};
List::List(){
	head = new node;
	head->data = 0;
	head->next = NULL;
	head->pre = NULL;
}
void List::push_back(int elem){
	node *swap,*temp;
	swap = new node;
	temp = head;
	swap->data = elem;
	++length;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = swap;
	swap->pre = temp;
	swap->next = NULL;
}
void List::pop_back(){
	node *temp = head;
	node *swap;
	while(temp->next->next!=NULL)
		temp = temp->next;
	swap = temp->next;
	temp->next = NULL;
	delete swap;
	--length;
}
int List::back(){
	node *temp = head->next;
	while(temp->next !=NULL){
		temp = temp->next;
	}
	return temp->data;
}
int List::front(){
	return head->next->data;
}
bool List::empty(){
	return length == 0? 1 : 0;
}
int List::size(){
	return length;
}
void List::push_front(int elem){
	node *swap = new node;
	swap->data = elem;
	swap->next = head->next;
	head->next->pre = swap;
	head->next = swap;
	swap->pre = head;
	++length;
}
void List::pop_front(){
	node *swap = head->next;
	node *temp = head->next->next;
	head->next = temp;
	temp->pre = head;
	delete swap;
	swap = NULL;
	--length;
}
bool List::insert_after(int elem1,int elem2){
	node *swap = head->next;
	node *temp = new node;
	temp->data = elem2;
	while(swap->data != elem1){
		swap = swap->next;
		if(swap == NULL)
			return false;	
	}
	temp->next = swap->next;
	temp->pre = swap;	
	if(swap->next != NULL){
		swap->next->pre = temp;	
	}
	swap->next = temp;
	++length;
	return true;
}

bool List::insert_before(int elem1,int elem2){
	node *swap = head->next;
	node *temp = new node;
	temp->data = elem2;
	while(swap->data != elem1){
		swap = swap->next;
		if(swap == NULL)
			return false;
	}
	temp->next = swap;
	temp->pre = swap->pre;
	swap->pre->next = temp;
	swap->pre = temp;
	++length;
	return true;
}
void List::traverse(){
	node *swap = head->next;
	while(swap!=NULL){
		cout<<swap->data<<" ";
		swap = swap->next;
	}
}
bool List::remove(int elem){
	node *swap = head->next;
	node *temp;
	while(swap->data != elem){
		swap = swap->next;
		if(swap == NULL)
			return false;
	}
	temp = swap->pre;
	temp->next = swap->next;
	if(swap->next !=NULL)
		swap->next->pre = temp;
	--length;
	delete swap;
	swap = NULL;
	return true;
}
int main(int argc, char const *argv[])
{
	List list;
	for (int i = 1; i <= 5; ++i)
	{
		list.push_back(i);
	}
	if(list.insert_after(3,1) == 0){
		cout<<"not find"<<endl;
		return 0;
	}
//	list.pop_back();
	if(list.remove(1) == 0){
		cout<<"not find"<<endl;
		return 0;		
	}
	list.traverse();
//	list.pop_front();
//	list.pop_front();
	return 0;
}
