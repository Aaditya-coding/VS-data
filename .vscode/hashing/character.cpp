#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the string(lowerspace only): ";
    cin>>s;
    int hash[s.length()+1] = {0};
    for(int i=0;i<s.length();i++)
    {
        hash[int(s[i]-97)]++;
    }
    int q;
    cout<<"Enter the number of letters you want to check: ";
    cin>>q;
    cout<<"Enter the letters: ";
    while(q--)
    {
      char ch;
      cin>>ch;
      cout<<"\n "<<hash[(int)(ch-97)];
    }
    
}