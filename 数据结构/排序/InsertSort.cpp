//插入排序是稳定的
//插入排序——直接插入排序。
//时间复杂度：O(n^2	)
//思想：记录第一个元素为有序的子序列，从第二个元素开始，逐个插入，直到整体有序
//其他的插入排序有二分插入排序，2-路插入排序
#include<iostream>
using namespace std;
void print(int a[],int n,int i){
	printf("%d:\n",i );
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",a[i] );
	}
	printf("\n");
}
void InsertSort1(int a[],int n){
	int j,x;
	j = x = 0;
	for (int i = 1; i < n; ++i)		
	{
		if (a[i]<a[i-1])	//如果当前元素比前一个小，需向前移动有序
		{
			j = i-1;
			x = a[i];		//哨兵x
			while(j>=0 && x <a[j] ){	//找到一个位置使得前一个元素比他小
				a[j+1] = a[j];		//元素后移
				j--;
			}
			a[j+1] = x;		//a[j]<=x，将x插入j+1处
		}
		
		print(a,n,i);
	}
}
void InsertSort2(int a[],int n){
	for(int i = 1;i<n;i++){
		if(a[i]>a[i-1]){
			int j = i-1;
			int x = a[i];
			while(j>=0 && x>a[j]){
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = x;
		}
		print(a,n,i);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	int a[8] = {7,3,4,5,1,8,2,6};
	InsertSort1(a,8);	//<
	InsertSort2(a,8);	//>
	return 0;
}
