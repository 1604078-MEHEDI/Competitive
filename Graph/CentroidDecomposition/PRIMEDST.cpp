///https://www.quora.com/q/threadsiiithyderabad/Centroid-Decomposition-of-a-Tree
//https://www.codechef.com/problems/PRIMEDST
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
const int N = 5e4 + 10;
const int LOGN = 17;
set<int> g[N];
int dist[LOGN][N], sub[N];
int P[N], isPrime[N], len;
ll ans;
int nn;

void dfs1(int u, int p) {
  sub[u] = 1;
  nn++;
  for (auto it = g[u].begin(); it != g[u].end(); it++) {
    if (*it != p) {
      dfs1(*it, u);
      sub[u] += sub[*it];
    }
  }
}

int dfs2(int u, int p)
{
  for (auto it = g[u].begin(); it != g[u].end(); it++) {
    if (*it != p && sub[*it] > nn / 2) {
      return dfs2(*it, u);
    }
  }
  return u;
}

void dfs3(int u, int p, int depth, int d, int add)
{
  dist[depth][d] += add;
  for (auto it = g[u].begin(); it != g[u].end(); it++) {
    if (*it != p) dfs3(*it, u, depth, d + 1, add);
  }
}

ll dfs4(int u, int p, int depth, int d)
{
  ll ret = 0;
  for (int i = 0; i < len; i++) {
    if (P[i] - d < 0) continue;
    if (!dist[depth][P[i] - d]) break;
    if (P[i] != d) ret += dist[depth][P[i] - d];
    else ret += 2 * dist[depth][P[i] - d];
  }
  for (auto it = g[u].begin(); it != g[u].end(); it++)
    if (*it != p)
      ret += dfs4(*it, u, depth, d + 1);
  return ret;
}

void decompose(int root, int depth)
{
  nn = 0;
  dfs1(root, root);
  int centroid = dfs2(root, root);
  dfs3(centroid, centroid, depth, 0, 1);
  ll add = 0;
  int u = centroid;
  for (auto it = g[u].begin(); it != g[u].end(); it++) {
    dfs3(*it, u, depth, 1, -1);
    add += dfs4(*it, u, depth, 1);
    dfs3(*it, u, depth, 1, 1);
  }
  ans += add / 2;
  for (auto it = g[u].begin(); it != g[u].end(); it++) {
    g[*it].erase(u);
    decompose(*it, depth + 1);
  }
  for (int i = 0; i < N && dist[depth][i]; i++)
    dist[depth][i] = 0;
}

void genPrime()
{
  for (int i = 2;  i * i < N; i++) {
    if (!isPrime[i]) {
      for (int j = i * i; j < N; j += i) {
        isPrime[j] = 1;
      }
    }
  }
  P[len++] = 2;
  for (int i = 3; i < N; i += 2)
    if (!isPrime[i])
      P[len++] = i;
}

int main()
{
  //FASTIO
  ///*
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
//*/
  genPrime();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a - 1].insert(b - 1);
    g[b - 1].insert(a - 1);
  }
  decompose(0, 0);
  double den = (ll)n * (ll)(n - 1) / 2.0;
  printf("%0.10lf\n", ans / den);
  return 0;
}
