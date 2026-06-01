#include <bits/stdc++.h>
using namespace std;
int Vanara(int a, int b, int x, int y)
{
    int xc = a-x;
    int yc = b-y;
    if(xc<0) xc = xc * (-1);
    if(yc<0) yc = yc * (-1);
    return (xc+yc);
}

int Deva(int a, int b, int x, int y)
{
    int xc = (a-x)*(a-x);
    int yc = (b-y)*(b-y);
    int ans = xc+yc;
    return ans;
}
int Aryavarta(int a[],int b[],int n)
{
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i!=j)
            if((Vanara(a[i],b[i],a[j],b[j])*Vanara(a[i],b[i],a[j],b[j]))==Deva(a[i],b[i],a[j],b[j])) ans++;
        }
    }
    return (ans);
}
int main()
{
    int n;
    cin>>n;
    if(n>=1 and n<=100000)
    {
        int x[n],y[n];
        for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
        
        cout<<Aryavarta(x,y,n)<<endl;
    }
    else return 0;
}
