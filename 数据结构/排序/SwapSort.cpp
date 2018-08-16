#include<iostream>
using namespace std;

//√∞≈›≈≈–Ú
void BubbleSort(int a[],int n){
	bool flag = true;
	for(int i = 0;i<n-1 && flag;i++){
		flag = false;
		for(int j= 0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				flag = true;
			}
		}
	}
}
int get(int a[],int l,int r){
	int i = l - 1;
	int p = r - 1;
	int x = a[r];
	for(int j = l;j <= p;j++){
		if(a[j]<x){
			++i;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}
//øÏÀŸ≈≈–Ú
void QuickSort(int a[],int left,int right){
	if(left < right){
		int pat = get(a,left,right);
		QuickSort(a,left,pat-1);
		QuickSort(a,pat+1,right);
	}
}
int main(){
	int a[8] = {5,4,3,6,1,7,2,8};
	//BubbleSort(a,8);
	QuickSort(a,0,7);
	for(int i = 0;i<8;i++)
		printf("%d ",a[i]);
	return 0;
}
