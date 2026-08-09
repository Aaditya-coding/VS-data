//Slightly better than merge sort.
//Time Complexity = O(n log n).
//Space Complexity = O(1).
//Algorithm: 
//1)- Pick the pivot and place it in its correct place in the sorted array.
//    a)- 1st element in the array.
//    b)- last element in the array.
//    c)- median of the array.
//    d)- random element of the array.
//2)- Smaller on the left, larger on the right of the pivot.
#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j)
    {
        while(arr[i]<=pivot and i<=high-1) i++;
        while(arr[j]>pivot and j>=low+1) j--;
        if(i<j) swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j; 
}
void qs(int arr[], int low, int high)
{
    if(low<high)
    {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex-1);
        qs(arr, pIndex+1, high);
    }
}
int main()
{
  int n;
  cout<<"Enter the size of array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements: ";
  for(int i=0;i<n;i++)
  cin>>arr[i];
  qs(arr,0,n-1);
  cout<<"Array before sorting: \n";
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<"\nArray after sorting: \n";
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
}