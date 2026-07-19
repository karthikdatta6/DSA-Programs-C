#include <stdio.h>
#define MAX 5
void depth_first_search(int adj[][MAX],int visited[],int start)
{
     int stack[MAX];
     int top = -1;
     int i;
     printf("%c -> ",start+65);
     visited[start] = 1;
     stack[++top] = start;
     while(top != -1)
     {
        start = stack[top];
        for(i = 0; i < MAX; i++)
        {
        if(adj[start][i] && visited[i] == 0)
        {
            stack[++top] = i;
            printf("%c -> ", i + 65);
            visited[i] = 1;
            break;
         }
       }
     if(i == MAX)
        top--;
      }
}
int main()
{
     int adj[MAX][MAX]= {{0, 1, 0, 1, 0},
                  {1, 0, 1, 1, 0}, 
                  {0, 1, 0, 0, 1}, 
                  {1, 1, 0, 0, 1}, 
                  {0, 0, 1, 1, 0} };
     int visited[MAX] = {0};
     int i, j;
     printf("\n Enter the adjacency matrix: ");
     printf("DFS Traversal: ");
     depth_first_search(adj,visited,3);
    printf("\n");
     return 0;
}
