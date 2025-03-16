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