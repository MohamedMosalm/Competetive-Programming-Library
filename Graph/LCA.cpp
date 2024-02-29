#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, M = 19;
int ST[M][N], depth[N];
vector<int> adj[N];

void Build(int cur = 1, int par = 0)
{
  ST[0][cur] = par;
  for (int i = 1; i < M; ++i)
    ST[i][cur] = ST[i - 1][ST[i - 1][cur]];

  for (int x : adj[cur])
    if (x != par)
      depth[x] = depth[cur] + 1, Build(x, cur);
}

int Kth(int u, int k)
{
  if (!k)
    return u;
  int d = depth[u] - k;
  for (int i = M - 1; ~i; --i)
  {
    int nu = ST[i][u];
    if (nu && depth[nu] > d)
      u = nu;
  }
  return ST[0][u];
}

int LCA(int a, int b)
{
  if (depth[a] > depth[b])
    a = Kth(a, depth[a] - depth[b]);
  else if (depth[b] > depth[a])
    b = Kth(b, depth[b] - depth[a]);
  if (a == b)
    return a;
  for (int j = M - 1; ~j; --j)
    if (ST[j][b] != ST[j][a])
      a = ST[j][a], b = ST[j][b];
  return ST[0][a];
}

int dist(int u, int v)
{
  return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}