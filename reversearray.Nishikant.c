#include<stdio.h>
void main()
{
	int size,index1,lastindex,temp;
	int arr[20];
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	lastindex=size-1;
	printf("Enter %d elements into array:\n",size);
	for(int index1=0;index1<size;index1++)
	{
		scanf("%d",&arr[index1]);
	}
	for (index1=0;index1<size/2;index1++)
	{
		temp=arr[index1];
		arr[index1]=arr[lastindex];
		arr[lastindex]=temp;
		lastindex--;
	}
	printf("After reversing:\n");
	for(int index1=0;index1<size;index1++)
	{
		printf("%d\t",arr[index1]);
	}
}