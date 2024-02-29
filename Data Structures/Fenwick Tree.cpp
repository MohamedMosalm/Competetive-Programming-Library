#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct fenwickTree
{
    int n;
    vector<T> BIT;

    fenwickTree(int n) : n(n), BIT(n + 1)
    {
    }

    T getAccum(int idx)
    {
        T sum = 0;
        while (idx)
        {
            sum += BIT[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void set(int idx, T val)
    {
        val = val - getSum(idx, idx);
        add(idx, val);
    }

    void add(int idx, T val)
    {
        assert(idx != 0);
        while (idx <= n)
        {
            BIT[idx] += val;
            idx += (idx & -idx);
        }
    }

    T getSum(int l, int r)
    {
        if (r < l)
            return 0;
        return getAccum(r) - getAccum(l - 1);
    }
};