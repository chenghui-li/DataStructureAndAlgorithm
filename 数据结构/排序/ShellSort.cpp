#include<iostream>
using namespace std;
void print(int num[],int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",num[i] );
	}
	printf("\n");
}
void ShellInsertSort(int num[],int dk,int n){
	for(int i = dk;i<n;i++){
		if(num[i]<num[i-dk]){
			int j = i-dk;
			int x = num[i];
			while(x<num[j] && j>=0){
				num[j+dk] = num[j];
				j -=dk;
			}
			num[j+dk] = x;
		}
		print(num,n);
	}
}
void ShellSort(int num[],int n){
	int dk = n/2;
	while(dk>=1){
		ShellInsertSort(num,dk,n);
		dk /= 2;
	}
}
int main(int argc, char const *argv[])
{
	int num[] = {8,7,6,5,4,3,2,1};
	ShellSort(num,8);
	return 0;
}
