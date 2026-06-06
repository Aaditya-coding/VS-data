#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(12);
    v.emplace_back(23);
    v.push_back(34);      //{} --> {12,23,34}
    vector<int>::iterator it = v.begin();

    it++;
    cout<<*(it)<<" "<<endl;
    
    // vector<int>::iterator it = v.end();  //points to the end element of vector.
    // vector<int>::iterator it = v.rend(); //points to the right of end(beginning), it-- make it move in forward direction.
    // vector<int>::iterator it = v.rbegin(); //points to the left of beginning(end), it++ make it move in reverse direction.

    cout<<v[0]<<" "<<v.at(1)<<endl;
    cout<<v.back()<<" "<<endl; // the element at last.

    for(vector<int>::iterator i = v.begin(); i!=v.end();i++)  //v.end() points to right after end.
    {
        cout<<*(i)<<" ";
    }
     cout<<endl;
    for(auto it = v.begin(); it!=v.end(); it++)
    {
        cout<<*(it)<<" ";
    }
     cout<<endl;
    for(auto lit:v)
    {
        cout<<lit<<" ";
    }
}