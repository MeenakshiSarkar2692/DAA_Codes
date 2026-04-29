#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
clock_t start,end;

int main(){
    double difftm;
    int i,j,n,num,flag=0;
    int arr[1000];
    printf("\nEnter the limit:");
    scanf("%d",&n);
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++){
        arr[i]=(rand()%RAND_MAX)+1;
    }
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    start=clock();
    printf("\nEnter value to be searched: ");
    scanf("%d",&num);
    for(j=0;j<=n;j++){
        if(arr[j]==num){
            flag=1;
            break;
        }
    }
    end=clock();
    difftm = (double)(end-start)/(double)CLOCKS_PER_SEC;
   
    if(flag==1){
        printf("\nElement Found\n");
    }
    else{
        printf("\nElement Not Found\n");
    } 
    printf("Time: %f",difftm);
}