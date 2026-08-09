// swap two elements by check their magnitude and iterate through array
// Time Complexity = O(n^2) [for all cases] // use swap optimisation if you want to get O(n) in already sorted case
// Space Complexity = O(1)
#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void bubble_sort(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);
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
    bubble_sort(arr,n);
    cout<<"Sorted array: \n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}