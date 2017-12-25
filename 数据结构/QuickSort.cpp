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
void QuickSort(int a[],int start,int end){
	
    if(start>=end)
        return ;
    int pivotkey = a[end];
    int left = start;
    int right = end-1;
    while(left<right){
        while(a[left]<pivotkey && left < right)
            left++;
        while(a[right]>=pivotkey && left < right)
            right --;
        swap(a[left],a[right]);
    }
    if(a[left] > a[end])
        swap(a[left],a[end]);
    else 
        left ++;
    print(a,8);
    if(left)
        QuickSort(a,start,left-1);
    QuickSort(a,left+1,end);
}
int main(){
	int a[] = {3,7,6,1,8,4,2,5};
	QuickSort(a,0,8);
	return 0;
}
