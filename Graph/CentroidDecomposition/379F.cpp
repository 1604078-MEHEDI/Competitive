///https://codeforces.com/contest/379/problem/F
///similer: https://discuss.codechef.com/t/rrtree-editorial/3240

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


/* for Random Number generate
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
*/
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
const int N  = 1e6 + 6;
const int LG = 20;
vector<int> g[N];
int dis[LG][N];
int Lv[N];
int subTree[N], tot;
int par[N];
bool del[N];

void dfs(int u, int p)
{
  subTree[u] = 1;
  tot++;
  for (auto v : g[u]) {
    if (v == p || del[v])continue;
    dfs(v, u);
    subTree[u] += subTree[v];
  }
}

int get_center(int u, int p)
{
  for (auto v : g[u]) {
    if (del[v] || v == p)continue;
    if (subTree[v] > tot / 2) return get_center(v, u);
  }
  return u;
}

void setDis(int u, int p, int l, int f)
{
  dis[f][u] = l;
  for (auto v : g[u]) {
    if (del[v] || v == p)continue;
    setDis(v, u, l + 1, f);
  }
}

void decompose(int u, int p, int l)
{
  tot = 0;
  dfs(u, -1);
  int C = get_center(u, -1);
  setDis(C, -1, 0, l);
  par[C] = p;
  Lv[C] = l;
  del[C] = 1;
  for (auto v : g[C]) {
    if (del[v])continue;
    decompose(v, C, l + 1);
  }
}

int lca(int u, int v)
{
  int a = u;
  int b = v;
  if (Lv[u] < Lv[v]) swap(u, v);
  while (Lv[u] > Lv[v]) u = par[u];
  while (u != v) {
    u = par[u];
    v = par[v];
  }
  return dis[Lv[u]][a] + dis[Lv[v]][b];
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
  int n = 4;
  cin >> T;
  g[1].push_back(2);
  g[1].push_back(3);
  g[1].push_back(4);

  g[2].push_back(1);
  g[3].push_back(1);
  g[4].push_back(1);
  for (int i = 1; i <= T; i++) {
    int Q;
    cin >> Q;
    g[Q].push_back(n + 1);
    g[Q].push_back(n + 2);

    g[n + 1].push_back(Q);
    g[n + 2].push_back(Q);
    n += 2;
  }
  decompose(1, -1, 0);
  int x = 2, y = 4;
  int ans = 2;
  n = 4;
  for (int i = 1; i <= T; i++) {
    int p = lca(n + 1, x);
    int q = lca(n + 1, y);
    if (p > ans) {
      y = n + 1;
      ans = p;
    }
    if (q > ans)  {
      x = n + 1;
      ans = q;
    }
    cout << ans << endl;
    n += 2;
  }
  return 0;
}
