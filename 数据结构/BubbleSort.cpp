#include<iostream>
using namespace std;
void print(int a[],int n){
	for(int i = 0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void BubbleSort(int a[],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i;j++){
            if(a[j]>a[j+1])
                swap(a[j+1],a[j]);
        }
        print(a,n);
    }
}
int main(){
	int a[] = {8,7,6,5,4,3,2,1};
	BubbleSort(a,8);
	return 0;
} 
