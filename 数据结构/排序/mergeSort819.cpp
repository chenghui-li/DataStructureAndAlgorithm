#include<iostream>
using namespace std;
void merge(int a[],int s,int m,int t){
	int i = s;
	int j = m+1;
	int k = 0;
	int tmp[t-s+1];
	while(i <= m && j <= t){
		if(a[i]<a[j]){
			tmp[k++] = a[i++];
		}
		else
			tmp[k++] = a[j++]; 
	}
	while(i <= m)
		tmp[k++] = a[i++];
	while(j <= t)
		tmp[k++] = a[j++];
	for(int i = s;i<=t; i++){
		a[i] = tmp[i-s];
	}
}
void mergePass(int a[],int n,int h){
	int i = 0;
	int k;
	while(i <= n-2*h+1){
		merge(a,i,i+h-1,i+2*h-1);
		i = i+ 2*h;
	}
	if(i < n-h+1){
		merge(a,i,i+h-1,n-1);
	}

}
void mergeSort(int a[],int n){
	int h = 1;
	while(h<n){
		mergePass(a,n,h);
		h *= 2;
	}
}
void mergeSort2(int a[],int s,int t){
	if(s == t)
		return ;
	
	
		int m = (s+t)/2;
		mergeSort2(a,s,m);
		mergeSort2(a,m+1,t);
		merge(a,s,m,t);
}
int main(){
	int a[9] = {5,2,7,1,8,4,3,6,9};
//	mergeSort2(a,0,7);
	mergeSort(a,9);
	for(int i = 0;i<9;i++)
		printf("%d ",a[i]);
}
