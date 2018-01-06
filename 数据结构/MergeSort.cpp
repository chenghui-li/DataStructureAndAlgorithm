#include<iostream>
using namespace std;
void print(int a[],int start,int end){
	for(int i = start;i<=end;i++)
	    printf("%d ",a[i]);
	printf("\n");
}
void Merge(int a[],int start,int mid,int end){
	int i = start,j = mid+1,k = start;
	int r1[10];
	while(i<=mid && j <= end){
		if(a[i]<a[j])
		    r1[k++] = a[i++];
		if(a[j]<a[i])
		    r1[k++] = a[j++];
	}
	while(i<=mid)
	    r1[k++] = a[i++];
	while(j<=end)
	    r1[k++] = a[j++];
	for(int i = start;i<=end;i++)
	    a[i] = r1[i];
	print(a,start,end);
}
void MerSort1(int a[],int start,int end){
	if(start == end)
	    return;
	int mid = (start+end)/2;
	MerSort1(a,start,mid);
	MerSort1(a,mid+1,end);
	Merge(a,start,mid,end);
}
void Merge2(int a[],int start,int mid,int end){
	int i = start,j = mid+1,k = start;
	int r1[10];
	while(i<=mid && j<=end){
		if(a[i]>a[j])
		    r1[k++] = a[i++];
		if(a[j]>a[i])
		    r1[k++] = a[j++];
	}
	while(i<=mid)
	    r1[k++] = a[i++];
	while(j<=end)
	    r1[k++] = a[j++];
	for(int i = start;i<=end;i++){
		a[i] = r1[i];
	}
	print(a,start,end);
} 
void MerPass(int a[],int n,int h){
	int i = 1;
	while(i<=n-2*h+1){
		Merge2(a,i,i+h-1,i+2*h-1);
		i = i+2*h;
	}
	if(i<n-h+1)
	    Merge2(a,i,i+h-1,n);
}
void MerSort2(int a[],int n){   //a[1]----a[n] 
	int h = 1;
	while(h<n){
		MerPass(a,n,h);
		h*=2;
	}
}
int main(){
	int a[] = {0,3,7,1,6,2,8,4,5};
	MerSort1(a,1,8);
	MerSort2(a,8);
	return 0;
} 
