#include<stdio.h>
void main()
{
	int n,i,j;
	int arr[20];
	int temp[20];
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("Enter %d elements into array:\n",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=n-1,j=0;i>=0,j<n;i--,j++)
	{
		temp[j]=arr[i];
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=temp[i];
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	
}
