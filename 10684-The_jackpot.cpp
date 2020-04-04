#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n)
    {
        int mx = 0, dp = 0, dummy;
        for (int i = 0; i < n; i++)
        {
            cin>>dummy;
            dp = max(dp + dummy, dummy);
            mx = max(mx, dp);
        }
        if (mx)
            cout<<"The maximum winning streak is "<<mx<<"."<<endl;
        else cout<<"Losing streak."<<endl;
        cin>>n;
    }
    return 0;
}
