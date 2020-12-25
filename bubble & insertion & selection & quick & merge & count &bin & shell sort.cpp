#include<iostream>
#include<cmath>
using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int A[],int n)
{ int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
             swap(&A[j],&A[j+1]);
             flag=1;
             }
        }
        if(flag==0)
            break;
    }
}

void display(int A[],int n)
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void inertionsort(int A[],int n)
{
    int i,j,x;
    for(i=1;i<n-1;i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
void seletionsort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n-1;j++)
        {
            if(A[j]<A[k])
            {
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }
}

int iquicksort(int A[],int n)
{
    //quick sort//
    int pivot=A[1];
    int i=1;
    int j=n;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
            if(i<j)
            swap(&A[i],&A[j]);

    }while(i<j);
     swap(&A[1],&A[j]);
     return j;
}

// merge function definition used for merging sort//
void merge(int A[],int l,int mid,int h)
{
    int i,j,k;
    int B[100];
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

// count sort

int findmax(int A[],int n)
{
   int  max=-1;
    for(int i=0;i<n;i++)
    {
        if(A[i]>-1)
            max=A[i];
    }

    return max;
}
void countsort(int A[],int n)
{
    int max,i,j;
    int *c;
    max=findmax(A,n);
    c=new int [sizeof(int)*(max+1)];
    for(i=0;i<max+1;i++)
        c[i]=0;
    for(i=0;i<n;i++)
    {
        c[A[i]]++;
    }
    i=0;j=0;
    while(j<max+1)
    {
        if(c[j]>0)
        {
            A[i++]=j;
            c[j]--;
        }
        else
            j++;

    }
}
class Node{
public:
    int value;
    Node* next;
};

void Insert(Node** ptrBins, int idx){
    Node* temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr){ // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void BinSort(int A[], int n){
    int max = findmax(A,n);

    // Create bins array
    Node** bins = new Node* [max + 1];

    // Initialize bins array with nullptr
    for (int i=0; i<max+1; i++){
        bins[i] = nullptr;
    }

    // Update count array values based on A values
    for (int i=0; i<n; i++){
        Insert(bins, A[i]);
    }

    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (i < max+1){
        while (bins[i] != nullptr){
            A[j++] = Delete(bins, i);
        }
        i++;
    }

    // Delete heap memory
    delete [] bins;
}

void ShellSort(int A[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp)
        {
            A[j+gap]=A[j];
            j=j-gap;
        }
        A[j+gap]=temp;
        }
    }
}
int main()
{
    int A[]={8,5,7,3,2};
        bubblesort(A,5);
    display(A,5);
    cout<<endl;
    inertionsort(A,5);
    display(A,5);
    cout<<endl;
     seletionsort(A,5);
    display(A,5);

    cout<<endl;
     iquicksort(A,5);
    display(A,5);
    cout<<endl;

    imergesort(A,5);
    display(A,5);

    cout<<endl;
    cout<<"recursive merge sort"<<endl  ;
    rmergesort(A,0,5);
    display(A,5);
    cout<<endl;
    countsort(A,5);
    display(A,5);
      cout<<endl;
     cout<<"bin sort"<<endl;
    BinSort(A,5);
    display(A,5);
    cout<<endl;
    cout<<"shell sort"<<endl;
    ShellSort(A,5);
    display(A,5);
    cout<<endl;

return 0;
}
