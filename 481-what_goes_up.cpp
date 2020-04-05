#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree
{
private:
    vector<int> st;
    vector<T> A;
    int n;
    int left (int p)
    {
        return p << 1;
    }
    int right(int p)
    {
        return (p << 1) + 1;
    }
    int suitable(int u, int v)
    {
        return (A[u] >= A[v]) ? u : v;
    }
    void build(int p, int L, int R)
    {
        if (L == R)
            st[p] = L;
        else
        {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = suitable(p1, p2);
        }
    }

    int rmq(int p, int L, int R, int i, int j)
    {
        if (i >  R || j <  L)
            return -1;
        if (L >= i && R <= j)
            return st[p];

        int p1 = rmq(left(p), L, (L+R) / 2, i, j);
        int p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);

        if (p1 == -1)
            return p2;
        if (p2 == -1)
            return p1;
        return suitable(p1, p2);
    }
    int update_point(int p, int L, int R, int idx, T new_value)
    {
        int i = idx, j = idx;

        if (i > R || j < L)
            return st[p];

        if (L == i && R == j)
        {
            A[i] = new_value;
            return st[p] = L;
        }

        int p1, p2;
        p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
        p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

        return st[p] = suitable(p1, p2);
    }

public:
    SegmentTree(const vector<T> &_A)
    {
        A = _A;
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rmq(int i, int j)
    {
        if (i > j) return -1;
        return A[rmq(1, 0, n - 1, i, j)].second;
    }
    int update_point(int idx, T new_value)
    {
        return update_point(1, 0, n - 1, idx, new_value);
    }
};


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long long dummy, mx;
    int mxi;
    vector<long long> A;
    while (scanf("%lld", &dummy) == 1)
    {
        A.emplace_back(dummy);
    }
    int tot = 0;
    map<long long, int> mp;
    auto B = A;
    sort(B.begin(), B.end());
    for (auto val : B)
    {
        if (mp.count(val) == 0)
            mp[val] = tot++;
    }
    vector<int> dp(A.size(), 1), p(A.size(), -1);
    vector<pair<int, int> > tmp(tot, pair<int,int>(0, -1));
    SegmentTree<pair<int, int> > st(tmp);
    mx = 0; mxi = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int j = st.rmq(0, mp[A[i]] - 1);
        if (j == -1)
        {
            dp[i] = 1;
            p[i] = -1;
        }
        else
        {
            dp[i] = dp[j] + 1;
            p[i] = j;
        }
        if (dp[i] >= mx)
        {
            mx = dp[i];
            mxi = i;
        }
        st.update_point(mp[A[i]], make_pair(dp[i], i));
    }
    stack<int> ans;
    while (mxi != -1)
    {
        ans.push(A[mxi]);
        mxi = p[mxi];
    }
    printf("%d\n-\n", ans.size());
    while(!ans.empty())
    {
        printf("%d\n", ans.top());
        ans.pop();
    }
    return 0;
}
