#include <bits/stdc++.h>
using namespace std;

void solver()
{
    int n;
    cin>>n;
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>A[i][j];
            if (i)
                A[i][j] += A[i - 1][j]; //storing prefix sum for each col;
        }
    }
    int mx = -101;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int s = 0; s < n; s++)
            {
                int sum = 0;
                for (int tk = s; tk < n + s; tk++)
                {
                    int k = tk % n;
                    int val = A[j][k] - (i ? A[i - 1][k] : 0);
                    if (i > j)
                        val += A[n - 1][k];
                    sum = max(sum + val, val);
                    mx = max(mx, sum);
                }
            }
        }
    }
    cout<<mx<<endl;
}
int main()
{
    int tc;
    cin>>tc;
    while (tc--)
    {
        solver();
    }
}
