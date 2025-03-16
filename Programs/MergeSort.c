#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10
clock_t start,end;
double difftm;

void merge(int arr[],int P,int q,int r){
    int i,j,k;
    int n1= q-P+1;
    int n2= r-q;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[P+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[q+1+j];
    }
    i=0;
    j=0;
    k=P;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
     while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int P,int r){
    if(P<r){
        int q=(P+r)/2;
        mergesort(arr,P,q);
        mergesort(arr,q+1,r);
        merge(arr,P,q,r);
    }
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    srand((unsigned)time(NULL));
    int arr[max];
    for(int i=0;i<max;i++){
        arr[i]=rand();
    }
    printf("\nGiven Array:\n");
    print(arr,max);
    start =clock();
    mergesort(arr,0,max-1);
    end=clock();
    printf("\nSorted Array:\n");
    print(arr,max);
    difftm=(double)(end-start)/(double)(CLOCKS_PER_SEC);
    printf("\nTime taken: %lf",difftm);
}