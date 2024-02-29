#include <bits/stdc++.h>
using namespace std;

struct DSU
{
  vector<int> size;
  vector<int> parent;

  void init(int n)
  {
    size.resize(n + 1, 0);
    parent.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
      make_set(i);
    }
  }

  int find_set(int v)
  {
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }

  void make_set(int v)
  {
    parent[v] = v;
    size[v] = 1;
  }

  bool union_sets(int a, int b)
  {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
      if (size[a] < size[b])
        swap(a, b);
      parent[b] = a;
      size[a] += size[b];
      return true;
    }
    return false;
  }
};