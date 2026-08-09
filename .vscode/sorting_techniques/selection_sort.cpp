//Find the minimum and swap it with the element at first place.
//Perform same operation on the array but not on first element.
#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void selection_sort(int arr[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int mini = i;
        for(int j=i;j<=n-1;j++)
        {
            if(arr[j]<arr[mini]) mini = j;
        }
        swap(&arr[i],&arr[mini]);
    }
}
int main()
{
 int n;
 cout<<"Enter the size of array: ";
 cin>>n;
 int arr[n];
 cout<<"Enter the elements of array: ";
 for(int i=0;i<n;i++)
 cin>>arr[i];
 selection_sort(arr,n);
 cout<<"Sorted array: \n";
 for(int i=0;i<n;i++)
 cout<<arr[i]<<" ";
}