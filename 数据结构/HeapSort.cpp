#include<iostream>
using namespace std;
void print(int a[],int n){
	for(int i = 1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void HeapAdjust(int a[],int s,int m){
	int temp = a[s];
	for(int j = 2*s;j<=m;j*=2){
		if(j<m && a[j]<a[j+1])
		    j++;
		if(temp>a[j])
		    break;
		a[s] = a[j];
		s = j;
	}
	a[s] = temp;
}
void HeapSort(int a[],int n){
	
	for(int i = n/2;i>0;i--){
		HeapAdjust(a,i,n);
	}
	print(a,n);
	for(int i = n;i>1;i--){
		swap(a[i],a[1]);
		HeapAdjust(a,1,i-1);
		print(a,n);
	}
}
int main(){
	int a[] = {0,3,7,1,8,4,6,2,5};
	HeapSort(a,8);
	
} 
