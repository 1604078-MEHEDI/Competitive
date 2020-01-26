//https://www.youtube.com/watch?v=6Q7OrMi0Vvc&list=PLfBJlB6T2eOtMXgK3FLUTawHjzpIEySHF&index=8

#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1000005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;

inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


///**
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

// find_by_order(k) – ফাংশনটি kth ordered element এর একটা পয়েন্টার রিটার্ন করে। অর্থাৎ তুমি চাইলেই kth ইন্ডেক্সে কি আছে, সেটা জেনে ফেলতে পারছো!
// order_of_key(x) – ফাংশনটি x এলিমেন্টটা কোন পজিশনে আছে সেটা বলে দেয়।

//*//**___________________________________________________**/

const int N = 2e5 + 5;
vector<int> graph[N];
const int lg = 20;
// lAC: 1 based index

int a[N], level[N], P[N][lg];

void dfs(int u, int p)
{
  level[u] = 1 + level[p];
  P[u][0] = p;
  for (auto v : graph[u]) {
    if (v == p)continue;
    dfs(v, u);
  }
}

int lca(int u, int v)
{
  int l;
  if (level[u] < level[v]) swap(u, v);

  for (l = 0; (1 << l) <= level[u]; l++);
  l--;

  for (int i = l; i >= 0; i--) {
    if (level[u] - (1 << i) >= level[v]) u = P[u][i];
  }

  if (u == v) return u;

  for (int i = l; i >= 0; i--) {
    if (P[u][i] != -1 and P[u][i] != P[v][i]) {
      u = P[u][i];
      v = P[v][i];
    }
  }
  return P[u][0];
}

// Get the ancestor of node 'u'
//which is 'dis' distance above.

int getAncestor(int u, int dis)
{
  dis = level[u] - dis;
  int l = 0;
  for (; (1 << l) <= level[u]; l++);
  l--;

  for (int i = l; i >= 0; i--) {
    if (level[u] - (1 << i) >= dis) u = P[u][i];
  }
  return u;
}


// return the distance between two nodes
int dis(int u, int v)
{
  if (level[u] < level[v]) swap(u, v);
  int w = lca(u, v);
  return level[u] + level[v] - 2 * level[w];
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
  int n = 9;
  //cin >> n;
  // for (int i = 1; i < n; i++) {
  //   int u, v;
  //   cin >> u >> v;
  //   graph[u].push_back(v);
  //   graph[v].push_back(u);
  // }
  graph[1].push_back(2);
  graph[2].push_back(1);

  graph[1].push_back(3);
  graph[3].push_back(1);

  graph[1].push_back(4);
  graph[4].push_back(1);

  graph[2].push_back(5);
  graph[5].push_back(2);

  graph[3].push_back(6);
  graph[6].push_back(3);

  graph[3].push_back(7);
  graph[7].push_back(3);

  graph[3].push_back(8);
  graph[8].push_back(3);

  graph[4].push_back(9);
  graph[9].push_back(4);

  for (int i = 0; i < lg; i++)
    for (int j = 1; j <= n; j++) P[j][i] = -1;

  level[0] = -1;
  dfs(1, 0);

  for (int i = 1; i < lg; i++) {
    for (int j = 1; j <= n; j++) {
      if (P[j][i - 1] != -1)
        P[j][i] = P[P[j][i - 1]][i - 1];
    }
  }

  

  cout << "The LCA of 6 and 9 is " << lca(6, 9) << endl;
  cout << "The LCA of 5 and 9 is " << lca(5, 9) << endl;
  cout << "The LCA of 6 and 8 is " << lca(6, 8) << endl;
  cout << "The LCA of 6 and 1 is " << lca(6, 1) << endl;
  return 0;
}
