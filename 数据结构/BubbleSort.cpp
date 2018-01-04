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
void BubbleSort1(int a[],int n){
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(a[i]>a[j])
                swap(a[i],a[j]);
        }
        print(a,n);
    }
}
void BubbleSort2(int a[],int n){
	for(int i = 0;i<n-1;i++){
		for(int j = n-2;j>=i;j--){
			if(a[j]>a[j+1])
			    swap(a[j],a[j+1]);
		}
        print(a,n);
	}
}
void BubbleSort3(int a[],int n){
	bool flag = true;
	for(int i =0;i<n-1 && flag;i++){
		flag = false;
		for(int j =n-2;j>=i;j--){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				flag = true;
			}
		}
		
        print(a,n);
	}
}
int main(){
	int a[] = {2,1,3,4,5,6,7,8};
	BubbleSort3(a,8);
	return 0;
} 
