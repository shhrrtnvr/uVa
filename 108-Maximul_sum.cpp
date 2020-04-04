#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>A[i][j];
            if(i) A[i][j] += A[i - 1][j];
        }
    }
    int mx = 0;
    for (int i = 0; i+1 < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int sum = 0;
            for(int k = 0; k < n; k++)
            {
                int val = A[j][k] - (i ? A[i - 1][k] : 0);
                sum = (sum < 0 ? val : sum + val);
                if (sum > mx) mx = sum;
            }
        }
    }
    cout<<mx<<endl;

}
