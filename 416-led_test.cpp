#include <bits/stdc++.h>
using namespace std;
int R[10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011}; // R, representation of i is R[i]
int S[11]; //S, sequence stored as integer, S[i] = bitstring of abcdefg of ith signal
int n, dam; // dam for storing damaged led's


bool isValid(int pos, int val)
{
    if(pos == n)
        return true;
    if (val < 0)
        return false;
    if (S[pos] & (dam | ~R[val]))
        return false;
    int new_dam = R[val] & ~(S[pos] | dam);
    dam ^= new_dam;
    bool ret = isValid(pos + 1, val - 1);
    dam ^= new_dam;
    return ret;
}

void solver()
{
    dam = 0;
    bool res = false;
    for (int i = 0; !res && i < 10; i++)
    {
        res |= isValid(0, i);
    }
    cout<<(res ? "MATCH" : "MISMATCH" )<<endl;
}

void input()
{
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        reverse(s.begin(), s.end());
        S[i] = 0;
        for (int j = 0; j < 7; j++)
            if (s[j] == 'Y') S[i] |= (1 << j);
    }
}

int main()
{

    cin>>n;
    while (n)
    {
        input();
        solver();
        cin>>n;
    }
}
