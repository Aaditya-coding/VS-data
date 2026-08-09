//It is a much more optimised sorting algorithm.
//Divide and Merge. 
//Instead of breaking, play around with indexes.
//Time Complexity = O(log(base 2)n).
//Space Complexity = O(n) [in worst case].
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid, int h)
{
    vector <int> temp;
    int left = l;
    int right = mid+1;
    while(left<=mid and right<=h)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        } 
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=h)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=l;i<=h;i++)
    arr[i] = temp[i-l];
}
void merge_sort(int arr[], int l, int h)
{
  if(l == h) return;
  int mid = (l+h)/2;
  merge_sort(arr,l,mid);
  merge_sort(arr,mid+1,h);
  merge(arr,l,mid,h);
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
  cout<<"Array before merge sort: ";
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  merge_sort(arr,0,n-1);
  cout<<"\nArray after merge sort: ";
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
}