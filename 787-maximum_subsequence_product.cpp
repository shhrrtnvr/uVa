#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> ls;
    int dummy;
    while(1)
    {
        cin>>dummy;
        if (dummy == -999999) break;
        else ls.push_back(dummy);
    }
    int  product = 0, SZ = ls.size();
    int dp[SZ][SZ];
    for (int i = 0; i < SZ; i++)
    {
        for (int j = 0; j <= i; j++)
        {

        }
    }
}
