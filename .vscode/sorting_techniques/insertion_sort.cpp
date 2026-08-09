//take an element and place it in current order.
#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void insertion_sort(int arr[], int n)
{
  for(int i=0;i<=n-1;i++)
  {
    int j=i;
    while(j>0 && arr[j-1]>arr[j])
    {
      swap(&arr[j-1],&arr[j]);
      j--;
    }
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
    insertion_sort(arr, n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}