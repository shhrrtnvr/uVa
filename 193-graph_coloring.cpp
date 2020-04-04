#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > AdjList;
vector<int> maxis, mis;
int n, mx, cur;

void calc_mis(int p)
{
    if(p == n)
    {
        if (cur > mx)
        {
            maxis = mis;
            mx = cur;
        }
        return;
    }
    bool p_clr = true;
    for (int i = 0; i < AdjList[p].size() && p_clr; i++)
    {
        if (mis[AdjList[p][i]] == 1) p_clr = false;
    }
    if (p_clr)
    {
        cur++;
        mis[p] = 1;
        calc_mis(p + 1);
        mis[p] = 0;
        cur--;
    }
    if(cur + n - p - 1 > mx) calc_mis(p + 1);
    return;
}

void solver()
{
    int k;
    cin>>n>>k;
    AdjList.assign(n, vector<int>());
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin>>u>>v;
        u--; v--;
        AdjList[u].emplace_back(v);
        AdjList[v].emplace_back(u);
    }

    maxis.clear();
    mx = 0; cur = 0;
    mis.assign(n , 0);
    calc_mis(0);
    cout<<mx<<endl;
    int j = 0;
    for(int i = 0; i < maxis.size(); i++)
    {
        if (maxis[i])
        {
            if (j) cout<<" ";
            cout<< i + 1 ;
            j++;
        }
    }
    cout<<endl;
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
