#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegTree
{
private:
    vector<T> tree;
    int n;
    T neutral = 0;

    T combine(T a, T b)
    {
        return a + b;
    }

    void update(int ql, int qr, T v, int k, int sl, int sr)
    {
        if (ql <= sl && qr >= sr)
        {
            tree[k] = T(v);
            return;
        }
        if (qr < sl || sr < ql)
            return;
        int mid = (sl + sr) / 2;
        update(ql, qr, v, k << 1, sl, mid);
        update(ql, qr, v, (k << 1) | 1, mid + 1, sr);
        tree[k] = combine(tree[k << 1], tree[k << 1 | 1]);
    }

    T query(int ql, int qr, int k, int sl, int sr)
    {
        if (ql <= sl && qr >= sr)
            return tree[k];
        if (qr < sl || sr < ql)
            return neutral;
        int mid = (sl + sr) / 2;
        return combine(query(ql, qr, k << 1, sl, mid), query(ql, qr, k << 1 | 1, mid + 1, sr));
    }

public:
    void build(int inputN, vector<T> &a)
    {
        n = inputN;
        if (n & (n - 1))
            n = 1 << ((int)log2(n) + 1);

        tree.resize(n << 1);
        for (int i = 0; i < inputN; i++)
            tree[i + n] = T(a[i]);

        for (int i = inputN; i < n; i++)
            tree[i + n] = neutral;

        for (int i = n - 1; i >= 1; i--)
            tree[i] = combine(tree[i << 1], tree[(i << 1) | 1]);
    }

    void Update(int idx, T val)
    {
        this->update(idx, idx, val, 1, 0, n - 1);
    }

    T Query(int l, int r)
    {
        return this->query(l, r, 1, 0, n - 1);
    }
};