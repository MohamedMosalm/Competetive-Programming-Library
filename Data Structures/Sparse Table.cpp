#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, LOG = 19;
int n, sparse[N][LOG], v[N];

void preprocess()
{
    for (int i = 0; i < n; i++)
    {
        sparse[i][0] = v[i];
    }
    for (int k = 1; k < LOG; k++)
    {
        for (int i = 0; i + (1 << k) - 1 < n; i++)
        {
            sparse[i][k] = min(sparse[i][k - 1], sparse[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query(int l, int r)
{
    int length = r - l + 1;
    int k = 31 - __builtin_clz(length);
    return min(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}
