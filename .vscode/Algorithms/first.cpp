#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>p1, pair<int,int>p2)
{
  if(p1.second<p2.second) return true;
  if(p1.second>p2.second) return false;
  
  //they are same

  if(p1.first > p2.first) return true;
  return false;
}
int main()
{
    int a[] = {1,5,3,2};
    vector<int> v;
    int n;
    sort(a, a+n); // start is included while end is not included.
    sort(v.begin(), v.end());

    //sort(a, a+n, greater<int>); if you want to sort in descending order.

    pair<int,int>a[] = {{1,2},{2,1},{4,1}};

    //what if:
    //sort it according to second element.
    //if second element is same, then sort according to first element but in descending.

    
     sort(a, a+n, comp);//here comp is a self defined comparator 
                        //which is a boolean function.

    int num = 7;
    //int cnt = __builtin_popcount(); // return 3 (number of set bits)

    long long num = 165786578687;
    //int cnt = __builtin_popcountll();

    string s = "123"; // if you want to print all permutations of this string.

    do{
        cout<< s <<endl;
    }while(next_permutation(s.begin(), s.end()));
    
    //what if s = 231. It would still print all but not the ones before it.

    int maxi = *max_element(a, a+n);
}