#include<iostream>
using namespace std;
//÷±Ω”≤Â»Î≈≈–Ú 
void InsertSort(int a[],int n){
	for(int i = 1;i<n;i++){
		if(a[i] < a[i-1]){
			int tmp = a[i];
			int j;
			for(j = i-1;tmp<a[j] && j>=0;j--){
				a[j+1] = a[j];
			}
			a[j+1] = tmp;
		}
	}
}
void ShellInsertSort(int a[],int dk,int n){
	for(int i = dk;i<n;i+=dk){
		if(a[i] < a[i-dk]){
			int tmp = a[i];
			int j;
			for(j = i-dk;j>=0 && tmp < a[j];j-=dk){
				a[j+dk] = a[j];
			}
			a[j+dk] = tmp;
		}
		for(int i = 0;i<n;i++){
			printf("%d ",a[i]);
		}
		cout<<endl;
	}
}
//œ£∂˚≈≈–Ú
void ShellSort(int a[],int n){
	int dk = n/2;
	while(dk >= 1){
		ShellInsertSort(a,dk,n);
		dk /= 2;
	}
} 
int main(){
	int a[8] = {5,4,3,6,1,7,2,8};
	//InsertSort(a,8);
	ShellSort(a,8);
	for(int i = 0;i<8;i++)
		printf("%d ",a[i]);
	return 0;	
}
