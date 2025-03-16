#include<stdio.h>
#include<stdlib.h>

int fibo(int n)
{
    int F[n];
    F[1]=0;
    F[2]=1;
    for(int i=3;i<=n;i++){
        F[i]=F[i-2]+F[i-1];
    }
    return F[n];
}

int main()
{
    int n;
    printf("Enter the limit:");
    scanf("%d",&n);
    int result=fibo(n);
    printf("%d", result);
    return 0;
}