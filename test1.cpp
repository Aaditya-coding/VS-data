#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b)
{
    int gcd = 1;
    int min = (a<b)?a:b;
    for(int i=1;i<=min;i++)
    {
        if(a%i==0 and b%i==0) gcd = i;
    }
    return ((a*b)/gcd);
}

int catalyst(int a, int b)
{
    int c = 0;
    for(int i=1;i<=a;i++)
    {
        if((lcm(a,i)*lcm(b,i))==(a*b)) c++;
    }
    return c;
}
int main()
{
    int t;
    cin>>t;
    int a[t],b[t];
    if(t>=1 and t<=1000)
    {
        for(int i=0;i<t;i++)
        {
          cin>>a[i]>>b[i];
        }
        for(int i=0;i<t;i++)
        {
          cout<<catalyst(a[i],b[i])<<endl;
        }
    }

}