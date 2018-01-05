#include<iostream>
using namespace std;
void print(int a[],int n){
	for(int i = 0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int patition(int a[],int left,int right){
	int i = left,j = right,temp;
	while(i<j){
		while(i<j && a[j]>=a[i])
		    j--;
		if(i<j){
			swap(a[i],a[j]);
			i++;
		}
			
		while(i<j && a[i]<=a[j])
		    i++;
		if(i<j){
			swap(a[i],a[j]);
			j--;
		}
		    
	}
	print(a,8);
	return i;
}
void QuickSort(int a[],int start,int end){
	
    if(start>=end)
        return ;
        
	int pivot = patition(a,start,end);
	QuickSort(a,start,pivot-1);
	
	QuickSort(a,pivot+1,end);
	
}
int main(){
	int a[] = {3,7,6,1,8,4,2,5};
	QuickSort(a,0,8);
	return 0;
}
