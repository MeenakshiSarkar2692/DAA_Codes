#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define V 4
int graph[V][V]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,0,1}};
int color[V];

void showColor(int color[])
{
    printf("\nThe Coloration is:\n");
    for(int i=0;i<V;i++)
    {
        printf("\nColor of vertex[%d]: %d",i,color[i]);
    }
}

bool isValid(int u,int color[],int c)
{
    for(int i=0;i<V;i++){
        if(graph[u][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoring(int colors,int color[],int vertex)
{
    if(vertex == V)
        return true;
    for(int col=1;col<=colors;col++){
        if (isValid(vertex,color,col)){
            color[vertex]=col;
            if(graphColoring(colors,color,vertex+1) == true)
                return true;
            color[vertex]=0;
        }
    }
    return false;
}

bool checkSolution(int m)
{
    for(int i=0;i<V;i++){
        color[i]=0;
    }
    if(graphColoring(m,color,0) == false){
        printf("\nSolution does not exist");
        return false;
    }
    showColor(color);
    return true;
}

int main()
{
    int colors=3;
    checkSolution(colors);
    return 0;
}
