#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SQRT
{
  vector<T> arr;
  vector<T> segs;
  int sq, n, nb;

  T neutral = 1e15;
  T combine(T &val1, T &val2)
  {
    return min(val1, val2);
  }

  void build(vector<T> &inputArr)
  {
    arr = inputArr;
    n = (int)arr.size();
    sq = sqrt(n);
    nb = (n + sq - 1) / sq;

    segs.assign(nb, neutral);

    for (int i = 0; i < n; ++i)
    {
      segs[i / sq] = combine(segs[i / sq], arr[i]);
    }
  }

  T query(int l, int r)
  {
    T ans = neutral;
    while (l % sq && l <= r)
    {
      ans = combine(ans, arr[l]);
      l++;
    }
    while (l + sq - 1 <= r)
    {
      ans = combine(ans, segs[l / sq]);
      l += sq;
    }
    while (l <= r)
    {
      ans = combine(ans, arr[l]);
      l++;
    }
    return ans;
  }

  void update(int idx, T val)
  {
    arr[idx] = val;
    int l = idx - idx % sq;
    int r = min(n - 1, l + sq - 1);
    n = arr.size();

    T ans = neutral;

    for (int i = l; i <= r; ++i)
    {
      ans = combine(ans, arr[i]);
    }

    segs[idx / sq] = ans;
  }
};