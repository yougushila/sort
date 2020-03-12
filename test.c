#include<stdio.h>



void bubbleSort(int arr[],int length){
	if(arr == NULL) return;
	int i,j;
	for(i = 0;i<length-1;i++){
		for(j=0;j<length-i-1;j++){
			if(arr[j+1] < arr[j]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	return;

}

void selectSort(int arr[],int length){
	if(arr == NULL) return;
	int i,j;
	for(i=0;i<length;i++){
		int tag =i;
		for(j=i+1;j<length;j++){
			if(arr[tag] > arr[j]){
				tag = j;
			}
		}
		if(tag != i){
			int tmp = arr[tag];
			arr[tag] = arr[i];
			arr[i] = tmp;
		}
	}
	return;
}


void quickSort(int *arr,int left,int right){

	if(arr == NULL) return;
	if(left < right){
	
		int i = left;
		int j = right;
		int tmp = arr[left];
		while(i < j){
			//int tmp = arr[left];
			while(tmp < arr[j] && i<j){
				j--;
			}
			arr[i] = arr[j];
			while(tmp > arr[i] && i<j){
				i++;
			}
			arr[j] = arr[i];
			int index;
			for(index = 0;index<=right;index++){
				printf("%d ",arr[index]);
			}
			printf("\n");
		}
		arr[i] = tmp;
		quickSort(arr,left,i-1);
		quickSort(arr,i+1,right);
	}else{
		return;
	}
}

void insertSort(int arr[],int length){
	if(arr == NULL) return; 
	int i,j;
	 for(i=1;i<length;i++){
	 	int tmp=arr[i];
		for(j=i-1;j>=0;j--){
			if(tmp < arr[j]){
				arr[j+1]=arr[j];
			}else{
				break;
			}
		}
		arr[j+1] = tmp;
	 }
	 return;
}
//优化
void insertSort1(int arr[],int length){
	if(arr == NULL) return;
	int i,j;
	for(i=1;i<length;i++){
		int tmp = arr[i];
		int left = 0;
		int right = i-1;
		while(left <= right){
			int mid = left + ((right - left)>>1);
			if(tmp < arr[mid]){
				right = mid-1;
			}else if(tmp > arr[mid]){
				left = mid +1;
			}
		}

		for(j=i-1;j>=left;j--){

			arr[j+1] = arr[j];
		}
		arr[left] = tmp;
	}
	return;
}

void shellSort(int arr[],int length){
	if(arr == NULL) return;
	int tag;
	int j,i;
	for(tag = length/2; tag >0 ; tag/=2){
		for(i=tag;i<length;i++){
			int tmp = arr[i];
			for(j=i-tag;j>=0;j-=tag){
				if(tmp < arr[j]){
					arr[j+tag] = arr[j];
				}else{
					break;
				}
			}
			arr[j+tag] = tmp;
		}
	
	}
	return;
}

int main(){
	int arr[]={4,5,1,8,3,10,6,9,7,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("len is %d\n",len);
	printf("before ========\n");
	int i=0;
	for( i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	quickSort(arr,0,len-1);
//	insertSort1(arr,len);
//	shellSort(arr,len);
//	selectSort(arr,len);
//	bubbleSort(arr,len);
	printf("after ==========\n");
	int j=0;
	for(j=0;j<len;j++){
		printf("%d ",arr[j]);
	}
	printf("\n");
	return 0;
}
