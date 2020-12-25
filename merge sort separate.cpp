#include<iostream>
#include<cmath>
using namespace std;
void merge(int A[],int l,int mid,int h)
{
    int i,j,k;
    int B[h+1];
    i=l;
    j=mid+1;
    k=l;
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];

    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
    {
        A[i]=B[i];
    }

}
// function for iterative merge sort

void imergesort(int A[],int n)
{
    int p,i,l,mid,h;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,h);
        }
        if(n-i>p/2)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(A, l, mid, n-1);
        }
    }
        if(p/2<n)
        {
            merge(A,0,p/2-1,n-1);
        }

}

//rmerge sort
void rmergesort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {

        mid=floor((l+h)/2);
        rmergesort(A,l,mid);
        rmergesort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}
void display(int A[],int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}


int main()
{
    int A[]={8,3,7,4,9,2,6,5};
    cout<<"iterative merge sort outout"<<endl;
    imergesort(A,8);
    display(A,8);

    cout<<endl;
    cout<<"recursive merge sort"<<endl  ;
    rmergesort(A,0,8);
    display(A,8);

return 0;
}
