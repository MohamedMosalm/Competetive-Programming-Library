#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SQRT
{
  vector<T> arr;
  vector<vector<T>> segs;
  int sq, n, nb;

  void build(vector<T> &inputArr)
  {
    arr = inputArr;
    n = (int)arr.size();
    sq = sqrt(n);
    nb = (n + sq - 1) / sq;

    segs.resize(nb);
    for (int i = 0; i < n; ++i)
    {
      segs[i / sq].push_back(arr[i]);
    }
    // preprocess every segment in segs here
  }

  T query(int l, int r, int val)
  {
    T ans = 0;
    while (l % sq && l <= r)
    {
      // brute force

      l++;
    }
    while (l + sq - 1 <= r)
    {
      int sid = l / sq;
      // calc answer for the entire preprocessed segment

      l += sq;
    }
    while (l <= r)
    {
      // brute force

      l++;
    }
    return ans;
  }

  void update(int idx, T val)
  {
    int sid = idx / sq;
    // update segment segs[sid]

    arr[idx] = val;
    // preprocess segment segs[sid] again
  }
};
