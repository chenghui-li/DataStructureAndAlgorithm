#include<iostream>
using namespace std;
void print(int num[],int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",num[i] );
	}
	printf("\n");
}
int getMin(int num[],int begin,int end){
	int min = begin;
	for (int i = begin+1; i < end; ++i)
	{
		if(num[i]<num[min])
			min = i;
	}
	return min;
}
void SelectSort(int num[],int n){
	for (int i = 0; i < n; ++i)
	{
		int min = getMin(num,i,n);
		if(min != i){
			int temp = num[i];
			num[i] = num[min];
			num[min] = temp;
		}
		print(num,n);
	}
}
/*简单选择排序的改进：二元选择排序*/
void SelectSort2(int num[],int n){
	for (int i = 0; i < n/2; ++i)
	{
		int min,max,temp;
		min = max = i;
		for (int j = i; j < n-i; ++j)
		{
			if(num[j]>num[max]){

				max = j;
				continue;
			}
			if(num[j]<num[min]){
				min = j;
			}

		}
		int ma = num[max];		//记录此时的值是为了防止被交换两次，比如4,3,2,1
		temp = num[min];
		num[min] = num[i];
		num[i] = temp;
		if(num[max] == ma){
			temp = num[max];
			num[max] = num[n-1-i];
			num[n-1-i] = temp;
		}
		
		print(num,n);
	}
}
int main(int argc,char *argv[]){
	int num[] = {8,7,6,5,4,3,2,1};
	//SelectSort(num,8);
	SelectSort2(num,8);
	return 0;
}

