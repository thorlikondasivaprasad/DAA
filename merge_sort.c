#include <stdio.h>
#include <stdlib.h>
void merge(int a[],int l,int mid,int r)
{
    int i,j,k;
    int n1=mid-l+1;
    int n2=r-mid;
    
    int L[n1],R[n2];
    
    for(i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=a[mid+1+j];
    }
    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1) //remaining elements of L
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2) //remaining elements of R
    {
        a[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int l,int r)
{
    int mid;
    if (l<r)
    {
        mid=l+(r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int printarray(int a[],int size)
{
    printf("The elements of the array : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
}
void main() 
{
    // int a[]={13,12,11,43,3,14};
    int i,n;
    printf("Enter no.of elements in array :");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int size=sizeof(a)/sizeof(a[0]);
    printarray(a,size);
    
    mergesort(a,0,size-1);
    
    printf("\n Resultant Array :\n");
    printarray(a,size);
    
}
