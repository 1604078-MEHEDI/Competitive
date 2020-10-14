//https://codeforces.com/contest/609/problem/E
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);

#define dbg1(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin() ) os << ", ";
    os << *it;
  }
  return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if ( it != v.begin() ) os << ", ";
    os << it -> first << " = " << it -> second ;
  }
  return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () { cerr << endl; }

template <typename T>
void faltu( T a[], int n ) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }
// Program showing a policy-based data structure.
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less 
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

/**___________________________________________________**/

struct Edge
{
  int weight;
  int u, v;
  int idx;
  bool operator < (Edge E) const {
    return weight < E.weight;
  }
};
const int nx = 200011;
vector<Edge> E;
int parent[nx];
int d[nx];
int pa[20][nx];
int dp[20][nx];
ll every[nx];
const int lg = 19;

int find(int x) {
  if (x == parent[x]) return x;
  else return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x != y) parent[x] = y;
}

vector<pair<int, int>> graph[nx];

void dfs(int u, int p)
{
  for (auto v : graph[u]) {
    if (v.first == p)continue;
    d[v.first] = d[u] + 1;
    dp[0][v.first] = v.second;
    pa[0][v.first] = u;
    dfs(v.first, u);
  }
}

int lca(int u, int v)
{
  if (d[u] > d[v]) swap(v, u);
  int ret = 0;
  for (int i = lg; i >= 0; i--) {
    if (d[v] - (1 << i) >= d[u]) {
      ret = max(ret, dp[i][v]);
      v = pa[i][v];
    }
  }
  if (u == v)return ret;
  for (int i = lg; i >= 0; i--) {
    if (pa[i][u] != pa[i][v]) {
      ret = max(ret, dp[i][u]);
      ret = max(ret, dp[i][v]);
      u = pa[i][u];
      v = pa[i][v];
    }
  }
  ret = max(ret, dp[0][u]);
  ret = max(ret, dp[0][v]);
  return ret;
}

ll res = 0;
void MST(int m)
{
  res = 0;
  sort(E.begin(), E.end());
  for (int i = 0; i < m; i++) {
    int u = E[i].u;
    int v = E[i].v;
    int w = E[i].weight;
    if (find(u) != find(v)) {
      merge(u, v);
      res += w;
      graph[u].push_back({v, w});
      graph[v].push_back({u, w});
    }
  }
}

int main()
{
  FASTIO
  ///*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
//*/
  int T;
  //scanf("%d", &T);
  T = 1;
  for (int cs = 1; cs <= T; cs++) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      E.push_back({w, u, v, i});
    }
    //sort(E.begin(), E.end());



    //dbg(res);
    MST(m);

    dfs(1, 0);

    for (int i = 1; i <= lg; i++) {
      for (int j = 1; j <= n; j++) {
        pa[i][j] = pa[i - 1][pa[i - 1][j]];
      }
    }

    for (int i = 1; i <= lg; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][pa[i - 1][j]]);
      }
    }

    for (int i = 0; i < m; i++) {
      int u = E[i].u;
      int v = E[i].v;
      int w = E[i].weight;
      int idx = E[i].idx;

      ll ret = res + w - lca(u, v);
      //dbg(ret, lca(u,v));
      every[idx] = ret;
    }

    for (int i = 1; i <= m; i++)
      cout << every[i] << "\n";
  }
  return 0;
}
