#include "bits/stdc++.h"

using namespace std;

struct KMP
{
  vector<int> F;
  string s, pat;

  KMP(string s, string pat) : s(s), pat(pat)
  {
    F.assign(s.size(), 0);
    GO();
  }

  int fail(char c, int l)
  {
    while (l && pat[l] != c)
    {
      l = F[l - 1];
    }
    if (pat[l] == c)
      ++l;
    return l;
  }

  void GO()
  {
    ComputeF();
    for (int l = 0, i = 0; s[i]; ++i)
    {
      l = fail(s[i], l);
      if (!pat[l])
      {
        cout << i - l + 1 << "\n";
      }
    }
  }

  void ComputeF()
  {
    F[0] = 0;
    for (int i = 1; pat[i]; ++i)
    {
      F[i] = fail(pat[i], F[i - 1]);
    }
  }
};

int main()
{
  string s, pat;
  cin >> s >> pat;
  KMP k = KMP(s, pat);
  return 0;
}