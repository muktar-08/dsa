#include<stdio.h>
int min(int a, int b)
{
return(a < b ? a : b);
}
void floyd(int D[][10],int n)
{
for(int k=1;k<=n;k++)
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
}
int main()
{
int n, cost[10][10];
printf("Enter no. of Vertices: ");
scanf("%d",&n);
printf("Enter the cost matrix\n");
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
scanf("%d",&cost[i][j]);
floyd(cost,n);
printf("All pair shortest path\n");
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
printf("%d ",cost[i][j]);
printf("\n");
}
}
