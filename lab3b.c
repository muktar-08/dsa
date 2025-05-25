#include<stdio.h>
void warshal(int A[][10],int n)
{
for(int k=1;k<=n;k++)
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
A[i][j]=A[i][j] || (A[i][k] && A[k][j]);
}
void main()
{
int n, adj[10][10];
printf("Enter no. of Vertices: ");
scanf("%d",&n);
printf("Enter the adjacency matrix\n");
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
scanf("%d",&adj[i][j]);
warshal(adj,n);
printf("Transitive closure of the given graph is\n");
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
printf("%d ",adj[i][j]);
printf("\n");
}
}
