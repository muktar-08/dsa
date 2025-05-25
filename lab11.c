#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
void merge(int a[], int low,int mid,int high)
{
int i,j,k,c[10000];
i=low, j=mid+1, k=0;
while((i<=mid) && (j<=high))
{
count++;
if(a[i]<a[j])
c[k++]=a[i++];
else
c[k++]=a[j++];
}
while(i<=mid)
c[k++]=a[i++];
while(j<=high)
c[k++]=a[j++];
for(i=low,j=0;j<k;i++, j++)
a[i]=c[j];
}
void merge_sort(int a[], int low, int high)
{
int mid;
if(low < high)
{
mid=(low+high)/2;
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
merge(a,low,mid,high);
}
}
int main()
{
int a[10000],n,i;
printf("Enter the number of elements in an array:");
scanf("%d",&n);
printf("All the elements:");
Page No. 30
srand(time(0));
for(i=0;i<n;i++)
{
a[i]=rand();
printf("%d ",a[i]);
}
merge_sort(a,0,n-1);
printf("\nAfter sorting\n");
for(i=0;i<n;i++)
printf("%d ", a[i]);
printf("\nNumber of basic operations = %d\n",count);
}
