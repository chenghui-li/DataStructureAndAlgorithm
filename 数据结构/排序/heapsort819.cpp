//heapSort
void heapAdjust(int a[],int s,int m){
	int tmp = a[s];
	for(int j = 2*s;j<=m;j*=2){
		if(j < m && a[j] <a[j+1])
			j++;
		if(tmp >= a[j]){
			break;
		}
		a[s] = a[j];
		s = j;
	}
	a[s] = tmp;
}
void heapSort(int a[],int n){
	for(int i = n/2;i>0;i--){
		heapAdjust(a,i,n);
	}
	for(int i = n;i>1;i--){
		swap(a[i],a[1]);
		heapAdjust(a,1,i-1);
	}
}