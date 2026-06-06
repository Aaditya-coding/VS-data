#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> mpp;  // map<key, value>
    map<int, pair<int, int>> mpp; // map stores unique keys in sorted order.
    map< pair<int, int>, int> mpp;

    mpp[1] = 2;
    //mpp.emplace({3, 1});

    mpp.insert({2, 4});

    // [{2,3}] = 10;
    
    for(auto it : mpp)
    {
        cout<<it.first<<" "<<it.second<<endl; // prints 1 2 
                                              //        2 4
                                              //        3 1 
    }
     cout<< mpp[1]; // 2
     cout<< mpp[5]; // 0

     auto it = mpp.find(3);
    // cout << *(it).second;

     auto it = mpp.find(5); // if 5 is not there then it will point to mp.end()

     //This is the syntax
     auto it = mpp.lower_bound(2);
     auto it = mpp.upper_bound(3);
     // erase, swap, size, empty, are same as above
}