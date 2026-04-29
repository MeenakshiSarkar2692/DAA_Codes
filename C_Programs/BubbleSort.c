#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxsize 10
clock_t start, end;
double difftm;

void bubblesort(int arr[],int size){
    for(int i=0; i<maxsize; i++){
        for(int j=0; j<maxsize-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[maxsize];
    for(int i=0; i<maxsize; i++){
        arr[i]=rand();
    }
    printf("Unsorted Array:\n");
    for(int i=0; i<maxsize; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    start=clock();
    bubblesort(arr,maxsize);
    end=clock();
   
    printf("\nSort array:\n");
    for(int i=0; i<maxsize; i++){
        printf("%d ",arr[i]);
    }
    difftm = (double)(end-start)/(double)(CLOCKS_PER_SEC);
    printf("\n\nTime: %lf",difftm);
    return 1;
    
}

