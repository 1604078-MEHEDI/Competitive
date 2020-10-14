
///https://codeforces.com/contest/379/problem/F
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
const int M = 20;
int dp[M][N];
int depth[N];
int a, b;
int q;
int n;
int ans;

void init()
{
  a = 2; //most distance pair of nodes
  b = 4; //most distance pair of nodes
  n = 4; // number of nodes in the tree
  ans = 2; //  distance btwn 2 abd 4
  dp[0][2] = 1; // parent of 2 is 1
  dp[0][3] = 1; // parent of 3 is 1
  dp[0][4] = 1; // parent of 4 is 1

  depth[1] = 0; // 1 is the root
  depth[2] = 1;
  depth[3] = 1;
  depth[4] = 1;
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int dif = depth[u] - depth[v];
  for (int i = 0; i < M; i++) {
    if ((dif >> i) & 1)u = dp[i][u];
  }

  if (u != v) {
    for (int i = M - 1; i >= 0; i--) {
      if (dp[i][u] != dp[i][v]) {
        u = dp[i][u];
        v = dp[i][v];
      }
    }
    u = dp[0][u];
  }
  return u;
}

int dist(int u, int v)
{
  return depth[u] + depth[v] - (depth[lca(u, v)] << 1);
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
  init();
  cin >> q;
  while (q--) {
    int Q;
    cin >> Q;
    dp[0][n + 1] = Q;
    dp[0][n + 2] = Q;
    for (int i = 1; i < M; i++) {// build lca table
      dp[i][n + 1] = dp[i - 1][dp[i - 1][n + 1]];
      dp[i][n + 2] = dp[i][n + 1];
    }
    depth[n + 1] = depth[Q] + 1;
    depth[n + 2] = depth[n + 1];
    int x = dist(n + 1, a);
    int y = dist(n + 2, b);
    if (x > ans) {
      ans = x;
      b = n + 1;
    }
    if (y > ans) {
      ans = y;
      a = n + 2;
    }
    cout << ans << endl;
    n += 2;
  }
  return 0;
}
