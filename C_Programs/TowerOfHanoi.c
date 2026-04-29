#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start,end;
double difftm;

void TOH(int disk,char S,char D,char A){
    if(disk==1){
        printf("\nMove Disk %d from %c to %c\n",disk,S,D);
    }
    else{
        TOH(disk-1,S,A,D);
        printf("\nMove Disk %d from %c to %c\n",disk,S,D);
        TOH(disk-1,A,D,S);
    }
}

int main(){
    srand((unsigned)time(NULL));
    int num;
    printf("Enter the number of disks: ");
    scanf("%d",&num);
    start= clock();
    TOH(num,'S','D','A');
    printf("\n");
    end = clock();
    difftm=(double)(end -start)/(double)CLOCKS_PER_SEC;
    printf ("Time taken by program is %.6lf seconds.",difftm );
    return 0;
}