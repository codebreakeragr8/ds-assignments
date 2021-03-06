// Merge Sort
// By Aman
#include<stdio.h>
#include<stdlib.h>
int B[100];
void merge(int A[],int l,int m,int h)//this function merges values from sorted arrays to array B
{
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=h)
	{
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
	}
	for(;i<=m;i++)
		B[k++]=A[i];
	for(;j<=h;j++)
		B[k++]=A[j];
	for(int x=l;x<=h;x++)//copying of merged values to original array
		A[x]=B[x];

}
void mergesort(int A[],int l, int h )//recursive function of mergesort 
{
	if(l<h)
	{
		int m=(l+h)/2;
		mergesort(A,l,m);
		mergesort(A,m+1,h);
		merge(A,l,m,h);
	}
}
int main()
{
	int n;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int A[n];
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	mergesort(A,0,n-1);
	printf("The sorted array is(merge sort)\n");
	for(int i=0;i<n;i++)
		printf("%d",A[i]);
	return 0;
}