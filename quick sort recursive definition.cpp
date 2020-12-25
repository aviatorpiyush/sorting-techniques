#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}
int partition(int A[],int l,int h)
{
int pivot=A[l];
int i=l,j=h;
do
{
do{i++;}while(A[i]<=pivot);
do{j--;}while(A[j]>pivot);
if(i<j)swap(&A[i],&A[j]);
}while(i<j);
swap(&A[l],&A[j]);
return j;
}
void QuickSort(int A[],int l,int h)
{
int j;
if(l<h)
{
j=partition(A,l,h);
QuickSort(A,l,j);
QuickSort(A,j+1,h);
}
}
void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
}
int main()
{
    int A[]={8,5,7,3,2,INT32_MAX};

    QuickSort(A,0,5);
     display(A,5);

return 0;
}

