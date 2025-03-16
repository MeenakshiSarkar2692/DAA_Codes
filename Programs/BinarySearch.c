#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define max 10
clock_t start,end;
double difftm;

int Bsearch(int arr[max],int x,int low,int high)
{
    int mid;
    if(low>=high){
        return -99;
    }
    else{
        mid=(low+high)/2;
        if((x == arr[mid])){
            return mid;
    }
    else if (x > arr[mid]){
        return Bsearch(arr,x,mid+1,high);
    }
    else{
        return Bsearch(arr,x,low,mid-1);
    }
    }
}

void print(int arr[],int n){
    for(int i =0 ;i <n;++i ){
        printf("%d ",arr[i]);
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[max];
    int num;
    for(int i=0;i<max;i++){
        arr[i]=rand();
    }
    print(arr,max);
    start = clock();
    printf("\nEnter the element to be searched: ");
    scanf("%d",&num);
    int result= Bsearch(arr,num,0,max);
    end=clock();
    if(result==-99){
        printf("Element not found");
    }
    else{
        printf("Element fouond at: %d",result);
    }
    
    difftm = (double)(end-start)/(double)CLOCKS_PER_SEC;
    printf("\nTime: %lf",difftm);
}