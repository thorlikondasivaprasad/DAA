#include <stdio.h>
// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[low];
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i=low+1,j=high,temp;
    while(i<j)
    {
        while(pivot>arr[i])
            i++;
        while(pivot<=arr[j])
            j--;
        if (i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }        
        else
            break;
    }
            temp=arr[low];
            arr[low]=arr[j];
            arr[j]=temp;
    return j;
}
// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, N - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
}
