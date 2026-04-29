#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define max 10
clock_t start,end;
double difftm;

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void MaxHeapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        MaxHeapify(arr,n,largest);
    }
}

void BuildMaxHeap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        MaxHeapify(arr,n,i);
    }
    printf("\nMax Heap:\n");
    print(arr,n);
}

void HeapSort(int arr[],int n){
    BuildMaxHeap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        MaxHeapify(arr,i,0);
    }
}

int main(){
    srand((unsigned)time(NULL));
    int arr[max];
    for(int i=0;i<max;i++){
        arr[i]=rand();
    }
    printf("\nUnsorted Array:\n");
    print(arr,max);
    start=clock();
    HeapSort(arr,max);
    end=clock();
    printf("\nSorted Array:\n");
    print(arr,max);
    difftm=(double)(end-start)/(double)(CLOCKS_PER_SEC);
    printf("\nTime: %lf",difftm);
}
